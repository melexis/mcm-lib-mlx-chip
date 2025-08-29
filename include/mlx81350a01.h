/**
 * @file
 * @brief Melexis MLX81350A01 chip database
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
 * @details This file was automatically generated using pymlxchip v4.13.0 and provides the
 * declarations of the Melexis MLX81350A01 chip database.
 */
#pragma once

#include <stddef.h>
#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const ProjectId_t mlx81350a01_project_ids[] = {
    {.id = 0x2601u, .name = "MLX81350-xDC-AMx-001"},
    {.id = 0x2602u, .name = "MLX81350-xDC-AMx-101"},
    {.id = 0x2603u, .name = "MLX81350-xDC-AMx-201"},
    {.id = 0x2604u, .name = "MLX81350-xLW-AMx-101"},
    {.id = 0x2605u, .name = "MLX81350-xLW-AMx-900"},
};

const Flash_t mlx81350a01_flash = {
    .start = 0x05800u,
    .length = 0x08000u,
    .page = 0x80u,
    .sector = 0x800u,
    .erase_unit = 0x800u,
    .erase_time = 25,
    .write_unit = 0x80u,
    .write_time = 80,
    .write_partial = true,
};

const FlashCs_t mlx81350a01_flash_cs = {
    .start = 0x05700u,
    .length = 0x00100u,
    .writeable = 0x80u,
    .page = 0x80u,
    .erase_time = 25,
    .write_time = 5,
};

const NvMemory_t mlx81350a01_nv_memory = {
    .start = 0x00800u,
    .length = 0x00240u,
    .writeable = 0x1B0u,
    .page = 0x8u,
    .write_time = 12.5,
};

const uint16_t mlx81350a01_programming_keys_values[] = {
    0x5648u, 0xA5E4u, 0xA5E3u, 0x0007u, 0xAA4Au
};

const ProgKeys_t mlx81350a01_programming_keys = {
    .length = sizeof(mlx81350a01_programming_keys_values) / sizeof(uint16_t),
    .values = mlx81350a01_programming_keys_values,
};

const PpmLoader_t mlx81350a01_ppm_loader = {
    .prog_keys = &mlx81350a01_programming_keys,
    .eeprom_verification_session = true,
    .flash_cs_programming_session = false,
};

const MlxChip_t mlx81350a01 = {
    .name = "MLX81350A01",
    .project_ids = {
        .length = sizeof(mlx81350a01_project_ids) / sizeof(ProjectId_t),
        .values = mlx81350a01_project_ids
    },
    .memories = {
        .flash = &mlx81350a01_flash,
        .flash_cs = &mlx81350a01_flash_cs,
        .nv_memory = &mlx81350a01_nv_memory,
    },
    .bootloaders = {
        .ppm_loader = &mlx81350a01_ppm_loader,
        .uart_loader = NULL,
    },
};

#ifdef __cplusplus
}
#endif
