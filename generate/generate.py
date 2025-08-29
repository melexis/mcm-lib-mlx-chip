#!/bin/env python3
"""Python mako application to generate the Melexis chip databases.

Copyright Melexis N.V.

This product includes software developed at Melexis N.V. (https://www.melexis.com).

Melexis N.V. has provided this code according to LICENSE file attached to repository
"""
from pathlib import Path
from mako.template import Template
from pymlxchip.helper import get_all_chipnames
from pymlxchip import MlxChipCamcu

CURRENT_DIR = Path(__file__).parent.resolve()
INC_DIR = CURRENT_DIR / ".." / "include"
SRC_DIR = CURRENT_DIR / ".." / "src"


def generate_file(mako_path, output_path, **kwargs):
    mako_template = Template(filename=str(mako_path))
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w") as outfile:
        outfile.write(mako_template.render(**kwargs))


def main():
    """Main function."""
    camcu_chips = []
    for chipname in get_all_chipnames("camcu"):
        camcu_chip = MlxChipCamcu(chip_name=chipname)
        if camcu_chip.active:
            if camcu_chip.uart_loader is not None or camcu_chip.ppm_loader is not None:
                camcu_chips.append(camcu_chip)

    for chip in camcu_chips:
        generate_file(CURRENT_DIR / "camcu_chip_db.h.mako", INC_DIR / f"{chip.full_name.lower()}.h", mlx_chip=chip)

    generate_file(CURRENT_DIR / "mlx_chip.c.mako", SRC_DIR / "mlx_chip.c", camcu_chips=camcu_chips)
    generate_file(CURRENT_DIR / "mlx_chip.h.mako", INC_DIR / "mlx_chip.h", camcu_chips=camcu_chips)


if __name__ == "__main__":
    main()
