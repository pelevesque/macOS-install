local wezterm = require 'wezterm'
local c = wezterm.config_builder()

c.initial_cols = 80
c.initial_rows = 40

c.font= wezterm.font 'IBM PLEX MONO'
c.font_size = 20

c.color_scheme = 'Catppuccin Macchiato'

    -- Removes Apple window resizing circles.
c.window_decorations = 'RESIZE'

-- c.enable_tab_bar = false

c.window_background_opacity = 0.97
c.macos_window_background_blur = 90

c.keys = {
        -- macOs style fullscreen toggle for system consistency.
    { key = 'f', mods = 'CTRL|CMD', action = wezterm.action.ToggleFullScreen },
}

return c
