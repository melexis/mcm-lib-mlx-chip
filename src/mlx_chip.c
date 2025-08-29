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
 * @details implementations of the Melexis chip databases.
 */

#include "mlx_chip.h"
#include "mlx81339a01.h"
#include "mlx81339a02.h"
#include "mlx81339b01.h"

const MlxChip_t * camcu_chips[] = {
    &mlx81339a01,
    &mlx81339a02,
    &mlx81339b01,
};

const MlxChip_t * mlxchip_getCamcuChip(uint16_t project_id) {
    for (uint16_t chip_index = 0u; chip_index < sizeof(camcu_chips) / sizeof(MlxChip_t *); chip_index++) {
        for (uint16_t id_index = 0u; id_index < camcu_chips[chip_index]->project_ids.length; id_index++) {
            if (camcu_chips[chip_index]->project_ids.values[id_index].id == project_id) {
                return camcu_chips[chip_index];
            }
        }
    }
    return NULL;
}

