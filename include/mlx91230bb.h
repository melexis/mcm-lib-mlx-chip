/**
 * @file
 * @brief Melexis MLX91230BB chip database
 * @internal
 *
 * @copyright (C) 2024-2025 Melexis N.V.
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
 * @details This file was automatically generated using pymlxchip v4.17.6 and provides the
 * declarations of the Melexis MLX91230BB chip database.
 * @{
 */
#pragma once

#include <stddef.h>

#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const mlx_project_id_t mlx91230bb_project_ids[] = {
    {.id = 0x0D03u, .name = "MLX9123x-KDC-BBA-000"},
    {.id = 0x0D04u, .name = "MLX91230KDC-BBA-100"},
    {.id = 0x0D05u, .name = "MLX91230KDC-BBC-000"},
    {.id = 0x0D06u, .name = "MLX91230KDC-BBC-100"},
    {.id = 0x0D07u, .name = "MLX91231KDC-BBC-000"},
    {.id = 0x0D08u, .name = "MLX91230KDC-BBC-200"},
    {.id = 0x0D09u, .name = "MLX91231KGO-BBC-000"},
};

const mlx_flash_t mlx91230bb_flash = {
    .start = 0x08000u,
    .length = 0x08000u,
    .page = 0x80u,
    .sector = 0x800u,
    .erase_unit = 0x800u,
    .erase_time = 30,
    .write_unit = 0x80u,
    .write_time = 7,
    .write_partial = true,
};

const mlx_flash_cs_t mlx91230bb_flash_cs = {
    .start = 0x07F00u,
    .length = 0x00100u,
    .writeable = 0x80u,
    .page = 0x80u,
    .erase_time = 30,
    .write_time = 7,
};

const mlx_nv_memory_t mlx91230bb_nv_memory = {
    .start = 0x00400u,
    .length = 0x00238u,
    .writeable = 0x200u,
    .page = 0x8u,
    .write_time = 12.5,
};

const uint16_t mlx91230bb_programming_keys_values[] = {
    0x5648u, 0xA5E4u, 0xA5E3u, 0x0007u, 0xAA4Au
};

const mlx_prog_keys_t mlx91230bb_programming_keys = {
    .length = sizeof(mlx91230bb_programming_keys_values) / sizeof(uint16_t),
    .values = mlx91230bb_programming_keys_values,
};

const mlx_ppm_loader_t mlx91230bb_ppm_loader = {
    .prog_keys = &mlx91230bb_programming_keys,
    .eeprom_verification_session = true,
    .flash_cs_programming_session = true,
};

const mlx_uart_loader_t mlx91230bb_uart_loader = {
    .prog_keys = &mlx91230bb_programming_keys,
};

const mlx_chip_t mlx91230bb = {
    .name = "MLX91230BB",
    .project_ids = {
        .length = sizeof(mlx91230bb_project_ids) / sizeof(mlx_project_id_t),
        .values = mlx91230bb_project_ids
    },
    .memories = {
        .flash = &mlx91230bb_flash,
        .flash_cs = &mlx91230bb_flash_cs,
        .nv_memory = &mlx91230bb_nv_memory,
    },
    .bootloaders = {
        .ppm_loader = &mlx91230bb_ppm_loader,
        .uart_loader = &mlx91230bb_uart_loader,
    },
};

/** @} */

#ifdef __cplusplus
}
#endif
