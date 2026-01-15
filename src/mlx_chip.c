/**
 * @file
 * @brief Melexis chip databases
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
 * @details Implementations of the Melexis chip databases.
 */
#include <stdint.h>

#include "mlx_chip.h"
/* camcu */
#include "mlx81113xaa.h"
#include "mlx81113xab.h"
#include "mlx81118xaa.h"
#include "mlx81118xab.h"
#include "mlx81119xaa.h"
#include "mlx81160a01.h"
#include "mlx81330b02.h"
#include "mlx81332b02.h"
#include "mlx81334a01.h"
#include "mlx81339a02.h"
#include "mlx81339b01.h"
#include "mlx81339b02.h"
#include "mlx81340b01.h"
#include "mlx81344b01.h"
#include "mlx81346b01.h"
#include "mlx81349a01.h"
#include "mlx81350a01.h"
#include "mlx81350b01.h"
#include "mlx81352a01.h"
#include "mlx81354a01.h"
#include "mlx91230aa.h"
#include "mlx91230ba.h"
#include "mlx91230bb.h"
/* ganymede */
#include "mlx90332c.h"

const mlx_chip_t * camcu_chips[] = {
    &mlx81113xaa,
    &mlx81113xab,
    &mlx81118xaa,
    &mlx81118xab,
    &mlx81119xaa,
    &mlx81160a01,
    &mlx81330b02,
    &mlx81332b02,
    &mlx81334a01,
    &mlx81339a02,
    &mlx81339b01,
    &mlx81339b02,
    &mlx81340b01,
    &mlx81344b01,
    &mlx81346b01,
    &mlx81349a01,
    &mlx81350a01,
    &mlx81350b01,
    &mlx81352a01,
    &mlx81354a01,
    &mlx91230aa,
    &mlx91230ba,
    &mlx91230bb,
};

const mlx_chip_t * ganymede_chips[] = {
    &mlx90332c,
};

const mlx_chip_t * mlxchip_get_camcu_chip(uint16_t project_id) {
    for (uint16_t chip_index = 0u; chip_index < sizeof(camcu_chips) / sizeof(mlx_chip_t *); chip_index++) {
        for (uint16_t id_index = 0u; id_index < camcu_chips[chip_index]->project_ids.length; id_index++) {
            if (camcu_chips[chip_index]->project_ids.values[id_index].id == project_id) {
                return camcu_chips[chip_index];
            }
        }
    }
    return NULL;
}

const mlx_chip_t * mlxchip_get_ganymede_chip(uint16_t project_id) {
    for (uint16_t chip_index = 0u; chip_index < sizeof(ganymede_chips) / sizeof(mlx_chip_t *); chip_index++) {
        for (uint16_t id_index = 0u; id_index < ganymede_chips[chip_index]->project_ids.length; id_index++) {
            if (ganymede_chips[chip_index]->project_ids.values[id_index].id == project_id) {
                return ganymede_chips[chip_index];
            }
        }
    }
    return NULL;
}

