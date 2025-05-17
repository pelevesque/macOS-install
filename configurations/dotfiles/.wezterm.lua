local wezterm = require 'wezterm'
local c = wezterm.config_builder()

c.initial_cols = 80
c.initial_rows = 40

c.font_size = 20
c.font= wezterm.font 'IBM PLEX MONO'

c.color_scheme = 'AdventureTime'

return c
