/*!
 * @copyright
 * Copyright (c) 2015-2018 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * @file sysfs_api.hpp
 * @brief Wrapper for sysfsref library and ioctl calls for reading block device attributes
 * */

#pragma once

#include "sysfs/abstract_sysfs_interface.hpp"

#include <vector>
#include <string>
#include <memory>

struct sysfs_device;

namespace agent {
namespace storage {

static constexpr std::uint32_t SSD_RPM_VALUE = 1;

/*!
 * @brief C++ wrapper for sysfs operations
 */
class SysfsApi {
public:

    /*! Block device */
    class HardDrive {
    private:
        std::string m_name{};
        std::string m_sysfs_path{};
        std::string m_device_path{};
        std::string m_manufacturer{};
        std::string m_model{};
        std::string m_serial_number{};
        double m_capacity_gb{};
        std::uint32_t m_rpm{};
        std::string m_type{};
        std::string m_interface{};

    public:

        /*! Default constructor */
        HardDrive() {}

        bool operator==(const HardDrive& drive) {
            return ((drive.get_serial_number() == get_serial_number()) &&
                (drive.get_model() == get_model()) &&
                (drive.get_device_path() == get_device_path()));
        }

        /*! Default copy constructor */
        HardDrive(const HardDrive&) = default;

        /*! Default assignment operator */
        HardDrive& operator=(const HardDrive&) = default;

        /*!
         * @brief Get hard drive name
         * @return Hard drive name
         * */
        const std::string& get_name() const {
            return m_name;
        }

        /*!
         * @brief Set hard drive name
         * @param[in] name Hard drive name
         * */
        void set_name(const std::string& name) {
            m_name = name;
        }

        /*!
         * @brief Get device path (/dev/...)
         * @return Device path
         * */
        const std::string& get_device_path() const {
            return m_device_path;
        }

        /*!
         * @brief Set hard drive device path (/dev/...)
         * @param[in] device_path Hard drive device path
         * */
        void set_device_path(const std::string& device_path) {
            m_device_path = device_path;
        }

        /*!
         * @brief Get hard drive capacity in GB
         * @return Hard drive capacity in GB
         * */
        double get_capacity_gb() const {
            return m_capacity_gb;
        }

        /*!
         * @brief Set hard drive capacity in GB
         * @param[in] capacity_gb Hard drive capacity in GB
         * */
        void set_capacity_gb(double capacity_gb) {
            m_capacity_gb = capacity_gb;
        }

        /*!
         * @brief Get hard drive RPM
         * @return Hard drive RPM
         * */
        std::uint32_t get_rpm() const {
            return m_rpm;
        }

        /*!
         * @brief Set hard drive RPM
         * @param[in] rpm Hard drive RPM
         * */
        void set_rpm(std::uint32_t rpm) {
            m_rpm = rpm;
        }

        /*!
         * @brief Get hard drive manufacturer
         * @return Hard drive manufacturer
         * */
        const std::string& get_manufacturer() const {
            return m_manufacturer;
        }

        /*!
         * @brief Set hard drive manufacturer
         * @param[in] manufacturer Hard drive manufacturer
         * */
        void set_manufacturer(const std::string& manufacturer) {
            m_manufacturer = manufacturer;
        }

        /*!
         * @brief Get hard drive model
         * @return Hard drive model
         * */
        const std::string& get_model() const {
            return m_model;
        }

        /*!
         * @brief Set hard drive model
         * @param[in] model Hard drive model
         * */
        void set_model(const std::string& model) {
            m_model = model;
        }

        /*!
         * @brief Get drive serial number
         * @return Hard drive serial number
         * */
        const std::string& get_serial_number() const {
            return m_serial_number;
        }

        /*!
         * @brief Set hard drive serial number
         * @param[in] serial_number Hard drive serial number
         * */
        void set_serial_number(const std::string& serial_number) {
            m_serial_number = serial_number;
        }

        /*!
         * @brief Get hard drive type
         * @return Hard drive type
         * */
        const std::string& get_type() const {
            return m_type;
        }

        /*!
         * @brief Set hard drive type
         * @param[in] type Hard drive type
         * */
        void set_type(const std::string& type) {
            m_type = type;
        }

        /*!
         * @brief Get hard drive interface
         * @return Hard drive interface
         * */
        const std::string& get_interface() const {
            return m_interface;
        }

        /*!
         * @brief Set hard drive interface
         * @param[in] interface Hard drive interface
         * */
        void set_interface(const std::string& interface) {
            m_interface = interface;
        }

        static constexpr const char TYPE_SSD[] = "SSD";
        static constexpr const char TYPE_HDD[] = "HDD";
    };

    /*!
     * @brief Singleton pattern. Get SysfsAPI instance
     *
     * @return  SysfsAPI instance. Create if not exist otherwise
     *          return existing instance.
     * */
    static SysfsApi* get_instance();

    /*!
     * @brief Get hard drives
     * @return drives Vector of discovered hard drives.
     * */
    std::vector<HardDrive> get_hard_drives();

    /*!
     * @brief Default destructor.
     * */
    virtual ~SysfsApi();

private:
    SysfsApi(std::shared_ptr<sysfs::AbstractSysfsInterface> sysfs_interface);

    bool m_is_virtual_device(const sysfs::SysfsDir& device);

    bool m_is_direct_access_device(const sysfs::SysfsDir& device);

    bool m_is_boot_device(const sysfs::SysfsDir& device);

    void m_read_block_device_attributes(const sysfs::SysfsDir& device, HardDrive& hard_drive);

    void m_read_ata_attributes(const sysfs::SysfsDir& device, HardDrive& hard_drive);

    void m_perform_sg_io(const sysfs::SysfsDir& device, std::unique_ptr<uint16_t[]>& p_hdio_data);

    void m_perform_hdio_drive_cmd(const sysfs::SysfsDir& device, std::unique_ptr<uint16_t[]>& p_hdio_data);

    void m_read_ata_string(std::string& value, size_t offset, size_t length, std::unique_ptr<uint16_t[]>& p_hdio_data);

    void m_read_rpm(uint32_t& rpm, std::unique_ptr<uint16_t[]>& p_hdio_data);

    void m_read_serial_number(std::string& serial_number, std::unique_ptr<uint16_t[]>& p_hdio_data);

    void m_read_model_number(std::string& serial_number, std::unique_ptr<uint16_t[]>& p_hdio_data);

    void m_read_manufacturer(std::string& manufacturer, std::unique_ptr<uint16_t[]>& p_hdio_data);

    sysfs::Path m_get_devfs_path(const sysfs::SysfsDir& device);

    void m_trim(std::string& input_string);

    std::vector<sysfs::SysfsMount> m_mount_points{};
    std::shared_ptr<sysfs::AbstractSysfsInterface> m_sysfs{};

    static constexpr double SECTORS_TO_GB = 512.0 / (1000.0 * 1000.0 * 1000.0) ; // a sector has 512 B
    static constexpr unsigned long long DIRECT_ACCESS_TYPE = 0;
    static constexpr const char DEV_FS[] = "/dev";
    static constexpr const char MTAB_FILE[] = "/etc/mtab";
    static constexpr const char VIRTUAL[] = "/virtual/";
    static constexpr const char SIZE[] = "size";
    static constexpr const char DEVICE_MODEL[] = "device/model";
    static constexpr const char DEVICE_TYPE[] = "device/type";
    static constexpr const char SYSFS_BLOCK_CLASS[] = "/sys/class/block";

    static constexpr std::uint32_t ATA_DATA_SIZE = 512+4;
};

}
}
