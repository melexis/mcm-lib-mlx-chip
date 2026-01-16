<%
from datetime import datetime
%>\
/**
 * @file
 * @brief Melexis chip databases
 * @internal
 *
 * @copyright (C) 2024-${datetime.now().year} Melexis N.V.
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
 * @addtogroup lib_mlx_chip Melexis Chip Databases Library
 *
 * @details Definitions of the Melexis chip databases.
 * @{
 */
#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mlx_project_id_s {
    uint16_t id;
    const char * name;
} mlx_project_id_t;

typedef struct mlx_project_ids_s {
    size_t length;
    const mlx_project_id_t * values;
} mlx_project_ids_t;

typedef enum mlx_memory_type_e {                /**< flash type enum */
    MEM_TYPE_AMALTHEA_XFE = 0,                  /**< Amalthea XFE flash type */
    MEM_TYPE_AMALTHEA_KF = 1,                   /**< Amalthea KF flash type */
    MEM_TYPE_GANYMEDE_XFE = 2,                  /**< Ganymede XFE flash type */
    MEM_TYPE_GANYMEDE_KF = 3,                   /**< Ganymede KF flash type */
    MEM_TYPE_AMALTHEA_XFE2 = 4,                 /**< Amalthea XFE flash type (256 bytes pages) */
} mlx_memory_type_t;                            /**< flash type */

typedef struct mlx_flash_s {
    uint32_t start;
    uint32_t length;
    uint32_t page;
    uint32_t sector;
    uint32_t erase_unit;
    double erase_time;
    uint32_t write_unit;
    double write_time;
    bool write_partial;
    mlx_memory_type_t type;
} mlx_flash_t;

typedef struct mlx_flash_cs_s {
    uint32_t start;
    uint32_t length;
    uint32_t writeable;
    uint32_t page;
    double erase_time;
    double write_time;
    mlx_memory_type_t type;
} mlx_flash_cs_t;

typedef struct mlx_nv_memory_s {
    uint32_t start;
    uint32_t length;
    uint32_t writeable;
    uint32_t page;
    double write_time;
    mlx_memory_type_t type;
} mlx_nv_memory_t;

typedef struct mlx_memories_s {
    const mlx_flash_t * flash;
    const mlx_flash_cs_t * flash_cs;
    const mlx_nv_memory_t * nv_memory;
} mlx_memories_t;

typedef struct mlx_prog_keys_s {
    size_t length;
    const uint16_t * values;
} mlx_prog_keys_t;

typedef struct mlx_ppm_loader_s {
    const mlx_prog_keys_t * prog_keys;
    bool eeprom_verification_session;
    bool flash_cs_programming_session;
} mlx_ppm_loader_t;

typedef struct mlx_uart_loader_s {
    const mlx_prog_keys_t * prog_keys;
} mlx_uart_loader_t;

typedef struct mlx_bootloaders_s {
    const mlx_ppm_loader_t * ppm_loader;
    const mlx_uart_loader_t * uart_loader;
} mlx_bootloaders_t;

typedef struct mlx_chip_s {
    const char * name;
    mlx_project_ids_t project_ids;
    mlx_memories_t memories;
    mlx_bootloaders_t bootloaders;
} mlx_chip_t;

extern const mlx_chip_t * camcu_chips[];

const mlx_chip_t * mlxchip_get_camcu_chip(uint16_t project_id);

extern const mlx_chip_t * ganymede_chips[];

const mlx_chip_t * mlxchip_get_ganymede_chip(uint16_t project_id);

/** @} */

#ifdef __cplusplus
}
#endif
