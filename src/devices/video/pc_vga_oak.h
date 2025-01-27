// license:BSD-3-Clause
// copyright-holders: Carl, Angelo Salese

#ifndef MAME_VIDEO_PC_VGA_OAK_H
#define MAME_VIDEO_PC_VGA_OAK_H

#include "pc_vga.h"
#include "pc_xga.h"

#include "screen.h"

class oak_oti111_vga_device : public svga_device
{
public:
	oak_oti111_vga_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock);

	u8 xga_read(offs_t offset);
	void xga_write(offs_t offset, u8 data);

	void ramdac_mmio_map(address_map &map);
	void oak_map(address_map &map);

	virtual uint8_t mem_r(offs_t offset) override;
	virtual void mem_w(offs_t offset, uint8_t data) override;

protected:
	virtual void device_add_mconfig(machine_config &config) override;
	virtual void device_start() override;
	virtual void device_reset() override;
	virtual uint16_t offset() override;
	virtual void recompute_params() override;

	virtual void io_3bx_3dx_map(address_map &map) override;
private:
	virtual space_config_vector memory_space_config() const override;

	address_space_config m_oak_space_config;

	required_device<xga_copro_device> m_xga;

	u8 m_oak_idx = 0;

	u8 m_memory_size = 0;
	u8 m_i2c_data = 0;
	u8 m_scratchpad[8]{};
	bool m_oak_gfx_mode = false;
	bool m_oti_map_select = false;
	u8 m_oti_aperture_select = 0;
	u32 m_oti_aperture_mask = 0x3ffff;
	u8 m_pixel_mode = 0;
	bool m_color_swap = false;
	u8 m_bpp = 0;
};

DECLARE_DEVICE_TYPE(OTI111, oak_oti111_vga_device)

#endif // MAME_VIDEO_PC_VGA_OAK_H
