/**
 * @file
 * @brief Melexis MLX90332C chip database
 * @internal
 *
 * @copyright (C) 2024-2026 Melexis N.V.
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
 * @details This file was automatically generated using pymlxchip v4.18.1 and provides the
 * declarations of the Melexis MLX90332C chip database.
 * @{
 */
#pragma once

#include <stddef.h>

#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const mlx_project_id_t mlx90332c_project_ids[] = {
    {.id = 0x6E01u, .name = "MLX90332C"},
};

const mlx_flash_t mlx90332c_flash = {
    .start = 0x08000u,
    .length = 0x08000u,
    .page = 0x80u,
    .sector = 0x800u,
    .erase_unit = 0x800u,
    .erase_time = 30,
    .write_unit = 0x80u,
    .write_time = 7,
    .write_partial = true,
    .type = MEM_TYPE_GANYMEDE_XFE,
};

const mlx_flash_cs_t mlx90332c_flash_cs = {
    .start = 0x07F00u,
    .length = 0x00100u,
    .writeable = 0x80u,
    .page = 0x80u,
    .erase_time = 30,
    .write_time = 7,
    .type = MEM_TYPE_GANYMEDE_XFE,
};

const mlx_nv_memory_t mlx90332c_nv_memory = {
    .start = 0x01000u,
    .length = 0x00240u,
    .writeable = 0x200u,
    .page = 0x8u,
    .write_time = 14.3,
    .type = MEM_TYPE_GANYMEDE_XFE,
};

const uint16_t mlx90332c_programming_keys_values[] = {
    0x5683u, 0x5AD7u, 0x5AD6u, 0x0047u, 0xAA4Au
};

const mlx_prog_keys_t mlx90332c_programming_keys = {
    .length = sizeof(mlx90332c_programming_keys_values) / sizeof(uint16_t),
    .values = mlx90332c_programming_keys_values,
};

const mlx_ppm_loader_t mlx90332c_ppm_loader = {
    .prog_keys = &mlx90332c_programming_keys,
    .eeprom_verification_session = true,
    .flash_cs_programming_session = true,
};

const mlx_chip_t mlx90332c = {
    .name = "MLX90332C",
    .project_ids = {
        .length = sizeof(mlx90332c_project_ids) / sizeof(mlx_project_id_t),
        .values = mlx90332c_project_ids
    },
    .memories = {
        .flash = &mlx90332c_flash,
        .flash_cs = &mlx90332c_flash_cs,
        .nv_memory = &mlx90332c_nv_memory,
    },
    .bootloaders = {
        .ppm_loader = &mlx90332c_ppm_loader,
        .uart_loader = NULL,
    },
};

/** @} */

#ifdef __cplusplus
}
#endif
