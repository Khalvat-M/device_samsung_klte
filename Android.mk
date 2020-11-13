#
# Copyright (C) 2020 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_DEVICE),klte)

include $(call all-subdir-makefiles,$(LOCAL_PATH))
include $(call all-makefiles-under,$(LOCAL_PATH))

include $(CLEAR_VARS)


# (SYMLINK FOR FIRMWARE/IMAGE)
DMVERITY_IMAGES := \
    dmverity.b00 dmverity.b01 dmverity.b02 dmverity.b03 dmverity.mdt

DMVERITY_SYMLINKS := $(addprefix $(TARGET_OUT_VENDOR)/firmware/,$(notdir $(DMVERITY_IMAGES)))
$(DMVERITY_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "DMVERITY firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /firmware/image/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(DMVERITY_SYMLINKS)

FP_ASM_IMAGES := \
    fp_asm.b00 fp_asm.b01 fp_asm.b02 fp_asm.b03 fp_asm.mdt

FP_ASM_SYMLINKS := $(addprefix $(TARGET_OUT_VENDOR)/firmware/,$(notdir $(FP_ASM_IMAGES)))
$(FP_ASM_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "FP_ASM firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /firmware/image/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(FP_ASM_SYMLINKS)

SECUREFP_IMAGES := \
    securefp.b00 securefp.b01 securefp.b02 securefp.b03 securefp.mdt

SECUREFP_SYMLINKS := $(addprefix $(TARGET_OUT_VENDOR)/firmware/,$(notdir $(SECUREFP_IMAGES)))
$(SECUREFP_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "SECUREFP firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /firmware/image/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(SECUREFP_SYMLINKS)

T2_IMAGES := \
    t2_ks_mi.b00 t2_ks_mi.b01 t2_ks_mi.b02 t2_ks_mi.b03 t2_ks_mi.mdt

T2_SYMLINKS := $(addprefix $(TARGET_OUT_VENDOR)/firmware/,$(notdir $(T2_IMAGES)))
$(T2_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "T2 firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /firmware/image/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(T2_SYMLINKS)

TZ_IMAGES := \
    tz_ccm.b00 tz_ccm.b01 tz_ccm.b02 tz_ccm.b03 tz_ccm.mdt \
    tz_otp.b00 tz_otp.b01 tz_otp.b02 tz_otp.b03 tz_otp.mdt \
    tz_iccc.b00 tz_iccc.b01 tz_iccc.b02 tz_iccc.b03 tz_iccc.mdt

TZ_SYMLINKS := $(addprefix $(TARGET_OUT_VENDOR)/firmware/,$(notdir $(TZ_IMAGES)))
$(TZ_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "TZ firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /firmware/image/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(TZ_SYMLINKS)

TZPR_IMAGES := \
    tzpr25.b00 tzpr25.b01 tzpr25.b02 tzpr25.b03 tzpr25.mdt

TZPR_SYMLINKS := $(addprefix $(TARGET_OUT_VENDOR)/firmware/,$(notdir $(TZPR_IMAGES)))
$(TZPR_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "TZPR firmware link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /firmware/image/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(TZPR_SYMLINKS)

endif
