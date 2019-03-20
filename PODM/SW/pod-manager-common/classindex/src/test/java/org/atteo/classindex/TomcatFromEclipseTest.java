/*
 * Copyright (c) 2017-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright 2013 Atteo.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.atteo.classindex;

import org.testng.annotations.Test;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Enumeration;

import static org.assertj.core.api.Assertions.assertThat;

public class TomcatFromEclipseTest {
    /*
     * When executed under Tomcat started from Eclipse with "Serve modules without
     * publishing" option turned on, ClassLoader::getResources() method returns the same
     * resource two times: first with incorrect path and second time with correct one.
     * So ignore the one which does not exist.
     */
    @Test
    public void testIncorrectEntriesReturned() {
        ClassLoader original = Thread.currentThread().getContextClassLoader();
        ClassLoader weird = new WeirdClassLoader(original);
        Thread.currentThread().setContextClassLoader(weird);

        try {
            Iterable<Class<?>> annotated = ClassIndex.getAnnotated(Component.class);
            assertThat(annotated).containsOnly(FirstComponent.class, SecondComponent.class,
                InnerClasses.InnerComponent.class, InnerClasses.InnerComponent.InnerInnerComponent.class);
        } finally {
            Thread.currentThread().setContextClassLoader(original);
        }
    }

    private static class WeirdClassLoader extends ClassLoader {
        private ClassLoader wrappedClassLoader;

        @SuppressWarnings({"checkstyle:RedundantModifier"})
        public WeirdClassLoader(ClassLoader wrappedClassLoader) {
            this.wrappedClassLoader = wrappedClassLoader;
        }

        @SuppressWarnings({"checkstyle:MethodLength", "checkstyle:AnonInnerLength"})
        @Override
        public Enumeration<URL> getResources(final String name) throws IOException {
            return new Enumeration<URL>() {
                private boolean dummyReturned;
                private Enumeration<URL> original = wrappedClassLoader.getResources(name);

                @Override
                public boolean hasMoreElements() {
                    return !dummyReturned || original.hasMoreElements();
                }

                @Override
                public URL nextElement() {
                    if (!dummyReturned) {
                        dummyReturned = true;
                        try {
                            return new URL("file:///some/non/existing/file/path/qpwoeur103841s");
                        } catch (MalformedURLException e) {
                            throw new RuntimeException(e);
                        }
                    }
                    return original.nextElement();
                }
            };
        }
    }
}
