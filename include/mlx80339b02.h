/**
 * @file
 * @brief Melexis MLX80339B02 chip database
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
 * @details This file was automatically generated using pymlxchip v4.19.0 and provides the
 * declarations of the Melexis MLX80339B02 chip database.
 * @{
 */
#pragma once

#include <stddef.h>

#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const mlx_project_id_t mlx80339b02_project_ids[] = {
    {.id = 0x290Au, .name = "MLX80339-KDC-BMX-210"},
};

const mlx_nv_memory_t mlx80339b02_nv_memory = {
    .start = 0x00800u,
    .length = 0x00400u,
    .writeable = 0x300u,
    .page = 0x80u,
    .write_time = 22,
    .type = MEM_TYPE_AMALTHEA_KF,
};

const uint16_t mlx80339b02_programming_keys_values[] = {
    0x5648u, 0xA5E4u, 0xA5E3u, 0x95A8u
};

const mlx_prog_keys_t mlx80339b02_programming_keys = {
    .length = sizeof(mlx80339b02_programming_keys_values) / sizeof(uint16_t),
    .values = mlx80339b02_programming_keys_values,
};

const mlx_uart_loader_t mlx80339b02_uart_loader = {
    .prog_keys = &mlx80339b02_programming_keys,
};

const mlx_chip_t mlx80339b02 = {
    .name = "MLX80339B02",
    .project_ids = {
        .length = sizeof(mlx80339b02_project_ids) / sizeof(mlx_project_id_t),
        .values = mlx80339b02_project_ids
    },
    .memories = {
        .flash = NULL,
        .flash_cs = NULL,
        .nv_memory = &mlx80339b02_nv_memory,
    },
    .bootloaders = {
        .ppm_loader = NULL,
        .uart_loader = &mlx80339b02_uart_loader,
    },
};

/** @} */

#ifdef __cplusplus
}
#endif
