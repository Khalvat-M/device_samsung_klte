/*
   Copyright (c) 2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#include "property_service.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;

// copied from build/tools/releasetools/ota_from_target_files.py
// but with "." at the end and empty entry
std::vector<std::string> ro_product_props_default_source_order = {
    "",
    "product.",
    "product_services.",
    "odm.",
    "vendor.",
    "system.",
    "system_ext.",    
};

void property_override(char const prop[], char const value[], bool add = true)
{
    auto pi = (prop_info *) __system_property_find(prop);

    if (pi != nullptr) {
        __system_property_update(pi, value, strlen(value));
    } else if (add) {
        __system_property_add(prop, strlen(prop), value, strlen(value));
    }
}

void vendor_load_properties()
{
    const std::string bootloader = GetProperty("ro.bootloader", "");

    const auto set_ro_product_prop = [](const std::string &source,
            const std::string &prop, const std::string &value) {
        auto prop_name = "ro.product." + source + prop;
        property_override(prop_name.c_str(), value.c_str(), false);
    };

    if (bootloader.find("G900AZ") == 0) {
        /* klteaio - Cricket MVNO */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/kltetu/klteaio:5.0/LRX21T/G900AZTUS3BQD1:user/release-keys");
            set_ro_product_prop(source, "device", "klteaio");
            set_ro_product_prop(source, "model", "SM-G900AZ");
            set_ro_product_prop(source, "name", "klteaio");
        }
        property_override("ro.build.description", "kltetu-user 5.0 LRX21T G900AZTUS3BQD1 release-keys");
        property_override("ro.build.product", "klteaio");
    } else if (bootloader.find("G900F") == 0) {
        /* kltexx */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/kltexx/klte:6.0.1/MMB29M/G900FXXU1CRH1:user/release-keys");
            set_ro_product_prop(source, "device", "klte");
            set_ro_product_prop(source, "model", "SM-G900F");
            set_ro_product_prop(source, "name", "klte");
        }
        property_override("ro.build.description", "kltexx-user 6.0.1 MMB29M G900FXXU1CRH1 release-keys");
        property_override("ro.build.product", "klte");
    } else if (bootloader.find("G900M") == 0) {
        /* klteub */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/klteub/klte:6.0.1/MMB29M/G900MUBS1CQD5:user/release-keys");
            set_ro_product_prop(source, "device", "klteub");
            set_ro_product_prop(source, "model", "SM-G900M");
            set_ro_product_prop(source, "name", "klteub");
        }
        property_override("ro.build.description", "klteub-user 6.0.1 MMB29M G900MUBS1CQD5 release-keys");
        property_override("ro.build.product", "klteub");
    } else if (bootloader.find("G900R4") == 0) {
        /* klteusc */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/klteusc/klteusc:6.0.1/MMB29M/G900R4VXS2CQC2:user/release-keys");
            set_ro_product_prop(source, "device", "klteusc");
            set_ro_product_prop(source, "model", "SM-G900R4");
            set_ro_product_prop(source, "name", "klteusc");
        }
        property_override("ro.build.description", "klteusc-user 6.0.1 MMB29M G900R4VXS2CQC2 release-keys");
        property_override("ro.build.product", "klteusc");
        property_override("ro.cdma.home.operator.alpha", "U.S. Cellular");
        property_override("ro.cdma.home.operator.numeric", "311220");
    } else if (bootloader.find("G900R7") == 0) {
        /* klteacg */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/klteacg/klteacg:6.0.1/MMB29M/G900R7WWU3CPL1:user/release-keys");
            set_ro_product_prop(source, "device", "klteacg");
            set_ro_product_prop(source, "model", "SM-G900R7");
            set_ro_product_prop(source, "name", "klteacg");
        }
        property_override("ro.build.description", "klteacg-user 6.0.1 MMB29M G900R7WWU3CPL1 release-keys");
        property_override("ro.build.product", "klteacg");
        property_override("ro.cdma.home.operator.alpha", "U.S. Cellular");
        property_override("ro.cdma.home.operator.numeric", "310000");
    } else if (bootloader.find("G900T") == 0) {
        /* kltetmo */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/kltetmo/kltetmo:6.0.1/MMB29M/G900TUVU1GQC2:user/release-keys");
            set_ro_product_prop(source, "device", "kltetmo");
            set_ro_product_prop(source, "model", "SM-G900T");
            set_ro_product_prop(source, "name", "kltetmo");
        }
        property_override("ro.build.description", "kltetmo-user 6.0.1 MMB29M G900TUVU1GQC2 release-keys");
        property_override("ro.build.product", "kltetmo");
    } else if (bootloader.find("G900V") == 0) {
        /* kltevzw */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "Verizon/kltevzw/kltevzw:6.0.1/MMB29M/G900VVRU2DQL1:user/release-keys");
            set_ro_product_prop(source, "device", "kltevzw");
            set_ro_product_prop(source, "model", "SM-G900V");
            set_ro_product_prop(source, "name", "kltevzw");
        }
        property_override("ro.build.description", "kltevzw-user 6.0.1 MMB29M G900VVRU2DQL1 release-keys");
        property_override("ro.build.product", "kltevzw");
        property_override("ro.cdma.home.operator.alpha", "Verizon");
        property_override("ro.cdma.home.operator.numeric", "311480");
    } else if (bootloader.find("G900W8") == 0) {
        /* kltecan */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/kltevl/kltecan:6.0.1/MMB29M/G900W8VLU1DQB2:user/release-keys");
            set_ro_product_prop(source, "device", "kltecan");
            set_ro_product_prop(source, "model", "SM-G900W8");
            set_ro_product_prop(source, "name", "kltecan");
        }
        property_override("ro.build.description", "kltevl-user 6.0.1 MMB29M G900W8VLU1DQB2 release-keys");
        property_override("ro.build.product", "kltecan");
    } else if (bootloader.find("S902L") == 0) {
        /* kltetfnvzw */
        for (const auto &source : ro_product_props_default_source_order) {
            set_ro_product_prop(source, "fingerprint", "samsung/kltetfnvzw/kltetfnvzw:4.4.2/KOT49H/S902LUDUAOD3:user/release-keys");
            set_ro_product_prop(source, "device", "kltetfnvzw");
            set_ro_product_prop(source, "model", "SM-S902L");
            set_ro_product_prop(source, "name", "kltetfnvzw");
        }
        property_override("ro.build.description", "kltetfnvzw-user 4.4.2 KOT49H S902LUDUAOD3 release-keys");
        property_override("ro.build.product", "kltetfnvzw");
        property_override("ro.cdma.home.operator.alpha", "TracFone");
        property_override("ro.cdma.home.operator.numeric", "310000");
    }

    const std::string device = GetProperty("ro.product.device", "");
    LOG(INFO) << "Found bootloader " << bootloader << ". " << "Setting build properties for " << device << ".\n";
}
