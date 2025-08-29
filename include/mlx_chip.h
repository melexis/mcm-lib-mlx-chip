/**
 * @file
 * @brief Melexis chip databases
 * @internal
 *
 * @copyright (C) 2025 Melexis N.V.
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
 * @details declarations of the Melexis chip databases.
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ProjectId {
    uint16_t id;
    const char * name;
} ProjectId_t;

typedef struct ProjectIds {
    size_t length;
    const ProjectId_t * values;
} ProjectIds_t;

typedef struct Flash {
    uint32_t start;
    uint32_t length;
    uint32_t page;
    uint32_t sector;
    uint32_t erase_unit;
    double erase_time;
    uint32_t write_unit;
    double write_time;
    bool write_partial;
} Flash_t;

typedef struct FlashCs {
    uint32_t start;
    uint32_t length;
    uint32_t writeable;
    uint32_t page;
    double erase_time;
    double write_time;
} FlashCs_t;

typedef struct NvMemory {
    uint32_t start;
    uint32_t length;
    uint32_t writeable;
    uint32_t page;
    double write_time;
} NvMemory_t;

typedef struct Memories {
    const Flash_t * flash;
    const FlashCs_t * flash_cs;
    const NvMemory_t * nv_memory;
} Memories_t;

typedef struct ProgKeys {
    size_t length;
    const uint16_t * values;
} ProgKeys_t;

typedef struct PpmLoader {
    const ProgKeys_t * prog_keys;
    bool eeprom_verification_session;
    bool flash_cs_programming_session;
} PpmLoader_t;

typedef struct UartLoader {
    const ProgKeys_t * prog_keys;
} UartLoader_t;

typedef struct Bootloaders {
    const PpmLoader_t * ppm_loader;
    const UartLoader_t * uart_loader;
} Bootloaders_t;

typedef struct MlxChip {
    const char * name;
    ProjectIds_t project_ids;
    Memories_t memories;
    Bootloaders_t bootloaders;
} MlxChip_t;

extern const MlxChip_t * camcu_chips[];

const MlxChip_t * mlxchip_getCamcuChip(uint16_t project_id);

#ifdef __cplusplus
}
#endif
