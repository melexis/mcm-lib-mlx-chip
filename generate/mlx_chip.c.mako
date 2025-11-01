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
 *
 * @details Implementations of the Melexis chip databases.
 */
#include <stdint.h>

#include "mlx_chip.h"
%for chip in sorted(camcu_chips, key=lambda x: x.full_name):
#include "${chip.full_name.lower()}.h"
%endfor

const mlx_chip_t * camcu_chips[] = {
%for chip in sorted(camcu_chips, key=lambda x: x.full_name):
    &${chip.full_name.lower()},
%endfor
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

