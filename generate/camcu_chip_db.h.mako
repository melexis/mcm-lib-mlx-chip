<%
from pymlxchip import __version__ as pymlxchip_version
from datetime import datetime

filename_macro = f"DB_{mlx_chip.full_name}_H_".upper()

def bool_to_c(value):
    return str(value).lower()

def print_prog_keys(keys):
    retval = ""
    for key in keys:
        retval += "0x%04Xu, " % key
    retval = retval[:-2]
    return retval
%>\
/**
 * @file
 * @brief Melexis ${mlx_chip.full_name} chip database
 * @internal
 *
 * @copyright (C) ${datetime.now().year} Melexis N.V.
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
 *
 * @endinternal
 *
 * @ingroup lib_mlx_chip
 *
 * @details This file was automatically generated using pymlxchip v${pymlxchip_version} and provides the
 * declarations of the Melexis ${mlx_chip.full_name} chip database.
 */
#pragma once

#include <stddef.h>
#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const ProjectId_t ${mlx_chip.full_name.lower()}_project_ids[] = {
% for project_id in mlx_chip.get_project_ids():
    {.id = ${"0x%04X" % project_id}u, .name = "${mlx_chip.get_order_code(project_id)}"},
% endfor
};
% if mlx_chip.flash is not None:

const Flash_t ${mlx_chip.full_name.lower()}_flash = {
    .start = ${"0x%05X" % mlx_chip.flash.start}u,
    .length = ${"0x%05X" % mlx_chip.flash.length}u,
    .page = ${"0x%X" % mlx_chip.flash.pagesize}u,
    .sector = ${"0x%X" % mlx_chip.flash.sectorsize}u,
    .erase_unit = ${"0x%X" % mlx_chip.flash.erase_size}u,
    .erase_time = ${mlx_chip.flash.erase_time},
    .write_unit = ${"0x%X" % mlx_chip.flash.write_size}u,
    .write_time = ${mlx_chip.flash.write_time},
    .write_partial = ${bool_to_c(mlx_chip.flash.partial_write)},
};
% endif
% if mlx_chip.flash_cs is not None:

const FlashCs_t ${mlx_chip.full_name.lower()}_flash_cs = {
    .start = ${"0x%05X" % mlx_chip.flash_cs.start}u,
    .length = ${"0x%05X" % mlx_chip.flash_cs.length}u,
    .writeable = ${"0x%X" % mlx_chip.flash_cs.writeable}u,
    .page = ${"0x%X" % mlx_chip.flash_cs.pagesize}u,
    .erase_time = ${mlx_chip.flash_cs.erase_time},
    .write_time = ${mlx_chip.flash_cs.write_time},
};
% endif
% if mlx_chip.nv_memory is not None:

const NvMemory_t ${mlx_chip.full_name.lower()}_nv_memory = {
    .start = ${"0x%05X" % mlx_chip.nv_memory.start}u,
    .length = ${"0x%05X" % mlx_chip.nv_memory.length}u,
    .writeable = ${"0x%X" % mlx_chip.nv_memory.writeable}u,
    .page = ${"0x%X" % mlx_chip.nv_memory.pagesize}u,
    .write_time = ${mlx_chip.nv_memory.write_time},
};
% endif
% if mlx_chip.programming_keys is not None:

const uint16_t ${mlx_chip.full_name.lower()}_programming_keys_values[] = {
    ${print_prog_keys(mlx_chip.programming_keys.keys)}
};

const ProgKeys_t ${mlx_chip.full_name.lower()}_programming_keys = {
    .length = sizeof(${mlx_chip.full_name.lower()}_programming_keys_values) / sizeof(uint16_t),
    .values = ${mlx_chip.full_name.lower()}_programming_keys_values,
};
% endif
% if mlx_chip.ppm_loader is not None:

const PpmLoader_t ${mlx_chip.full_name.lower()}_ppm_loader = {
% if mlx_chip.ppm_loader.prog_keys_session is not None:
    .prog_keys = &${mlx_chip.full_name.lower()}_programming_keys,
% else:
    .prog_keys = NULL,
% endif
% if mlx_chip.ppm_loader.eeprom_verification_session is not None:
    .eeprom_verification_session = true,
% else:
    .eeprom_verification_session = false,
% endif
% if mlx_chip.ppm_loader.flash_cs_programming_session is not None:
    .flash_cs_programming_session = true,
% else:
    .flash_cs_programming_session = false,
% endif
};
% endif
% if mlx_chip.uart_loader is not None:

const UartLoader_t ${mlx_chip.full_name.lower()}_uart_loader = {
% if mlx_chip.programming_keys is not None:
    .prog_keys = &${mlx_chip.full_name.lower()}_programming_keys,
% else:
    .prog_keys = NULL,
% endif
};
% endif

const MlxChip_t ${mlx_chip.full_name.lower()} = {
    .name = "${mlx_chip.full_name}",
    .project_ids = {
        .length = sizeof(${mlx_chip.full_name.lower()}_project_ids) / sizeof(ProjectId_t),
        .values = ${mlx_chip.full_name.lower()}_project_ids
    },
    .memories = {
% if mlx_chip.flash is not None:
        .flash = &${mlx_chip.full_name.lower()}_flash,
% else:
        .flash = NULL,
% endif
% if mlx_chip.flash_cs is not None:
        .flash_cs = &${mlx_chip.full_name.lower()}_flash_cs,
% else:
        .flash_cs = NULL,
% endif
% if mlx_chip.nv_memory is not None:
        .nv_memory = &${mlx_chip.full_name.lower()}_nv_memory,
% else:
        .nv_memory = NULL,
% endif
    },
    .bootloaders = {
% if mlx_chip.ppm_loader is not None:
        .ppm_loader = &${mlx_chip.full_name.lower()}_ppm_loader,
% else:
        .ppm_loader = NULL,
% endif
% if mlx_chip.uart_loader is not None:
        .uart_loader = &${mlx_chip.full_name.lower()}_uart_loader,
% else:
        .uart_loader = NULL,
% endif
    },
};

#ifdef __cplusplus
}
#endif
