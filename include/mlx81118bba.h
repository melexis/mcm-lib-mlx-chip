/**
 * @file
 * @brief Melexis MLX81118BBA chip database
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
 * @details This file was automatically generated using pymlxchip v4.22.0 and provides the
 * declarations of the Melexis MLX81118BBA chip database.
 * @{
 */
#pragma once

#include <stddef.h>

#include "mlx_chip.h"

#ifdef __cplusplus
extern "C" {
#endif

const mlx_project_id_t mlx81118bba_project_ids[] = {
    {.id = 0x1803u, .name = "MLX81118KLW-BBA-000-RE"},
};

const mlx_flash_t mlx81118bba_flash = {
    .start = 0x08000u,
    .length = 0x10000u,
    .page = 0x80u,
    .sector = 0x1000u,
    .erase_unit = 0x10000u,
    .erase_time = 1000,
    .write_unit = 0x80u,
    .write_time = 7,
    .write_partial = true,
    .type = MEM_TYPE_GANYMEDE_KF,
};

const mlx_nv_memory_t mlx81118bba_nv_memory = {
    .start = 0x00800u,
    .length = 0x00400u,
    .writeable = 0x300u,
    .page = 0x80u,
    .write_time = 10,
    .type = MEM_TYPE_GANYMEDE_KF,
};

const mlx_ppm_loader_t mlx81118bba_ppm_loader = {
    .prog_keys = NULL,
    .eeprom_verification_session = true,
    .flash_cs_programming_session = false,
};

const mlx_chip_t mlx81118bba = {
    .name = "MLX81118BBA",
    .project_ids = {
        .length = sizeof(mlx81118bba_project_ids) / sizeof(mlx_project_id_t),
        .values = mlx81118bba_project_ids
    },
    .memories = {
        .flash = &mlx81118bba_flash,
        .flash_cs = NULL,
        .nv_memory = &mlx81118bba_nv_memory,
    },
    .bootloaders = {
        .ppm_loader = &mlx81118bba_ppm_loader,
        .uart_loader = NULL,
    },
};

/** @} */

#ifdef __cplusplus
}
#endif
