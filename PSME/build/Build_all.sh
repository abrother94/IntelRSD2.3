cmake ../
grep -rl Werror . | grep flags.make | xargs sed -i 's/-Werror//g'
make all -j8 2>&1 | tee  RFbuild.log

