/**
 * @file
 * @brief Melexis MLX81354A01 chip database
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
 * @details This file was automatically generated using pymlxchip v4.16.0 and provides the
 * declarations of the Melexis MLX81354A01 chip database.
 */
#pragma once

#include <stddef.h>
#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const ProjectId_t mlx81354a01_project_ids[] = {
    {.id = 0x2801u, .name = "MLX81354-xDC-AMx-000"},
    {.id = 0x2802u, .name = "MLX81354-xDC-AMx-100"},
    {.id = 0x2803u, .name = "MLX81354-xDC-AMx-200"},
    {.id = 0x2804u, .name = "MLX81354-xLW-AMx-100"},
};

const Flash_t mlx81354a01_flash = {
    .start = 0x05800u,
    .length = 0x10000u,
    .page = 0x100u,
    .sector = 0x1000u,
    .erase_unit = 0x1000u,
    .erase_time = 30,
    .write_unit = 0x100u,
    .write_time = 7,
    .write_partial = true,
};

const FlashCs_t mlx81354a01_flash_cs = {
    .start = 0x05600u,
    .length = 0x00200u,
    .writeable = 0x100u,
    .page = 0x100u,
    .erase_time = 30,
    .write_time = 7,
};

const NvMemory_t mlx81354a01_nv_memory = {
    .start = 0x00400u,
    .length = 0x00640u,
    .writeable = 0x5B0u,
    .page = 0x8u,
    .write_time = 12.5,
};

const uint16_t mlx81354a01_programming_keys_values[] = {
    0x5648u, 0xA5E4u, 0xA5E3u, 0x0007u, 0xAA4Au
};

const ProgKeys_t mlx81354a01_programming_keys = {
    .length = sizeof(mlx81354a01_programming_keys_values) / sizeof(uint16_t),
    .values = mlx81354a01_programming_keys_values,
};

const PpmLoader_t mlx81354a01_ppm_loader = {
    .prog_keys = &mlx81354a01_programming_keys,
    .eeprom_verification_session = true,
    .flash_cs_programming_session = false,
};

const MlxChip_t mlx81354a01 = {
    .name = "MLX81354A01",
    .project_ids = {
        .length = sizeof(mlx81354a01_project_ids) / sizeof(ProjectId_t),
        .values = mlx81354a01_project_ids
    },
    .memories = {
        .flash = &mlx81354a01_flash,
        .flash_cs = &mlx81354a01_flash_cs,
        .nv_memory = &mlx81354a01_nv_memory,
    },
    .bootloaders = {
        .ppm_loader = &mlx81354a01_ppm_loader,
        .uart_loader = NULL,
    },
};

#ifdef __cplusplus
}
#endif
