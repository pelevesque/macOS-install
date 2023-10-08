----------------------------------------------------------------------
-- Set options.
local o = vim.opt

o.number = true
o.relativenumber = true
o.colorcolumn = '70,80'

    -- Tabs to spaces.
o.tabstop = 4
o.shiftwidth = 4
o.softtabstop = 4
o.expandtab = true
o.smarttab = true

vim.g.mapleader = " "

----------------------------------------------------------------------
-- Load plugins.
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
    vim.fn.system({
        "git",
        "clone",
        "--filter=blob:none",
        "https://github.com/folke/lazy.nvim.git",
        "--branch=stable", -- latest stable release
        lazypath,
    })
end

vim.opt.rtp:prepend(lazypath)

require("lazy").setup({
    "navarasu/onedark.nvim",
    "airblade/vim-gitgutter",
    "NvChad/nvim-colorizer.lua",
    "ojroques/nvim-hardline",
    "ThePrimeagen/vim-be-good",
})

require('onedark').setup { style = 'warmer' }
require('onedark').load()

require 'colorizer'.setup()

require('hardline').setup {}

----------------------------------------------------------------------
-- Color trailing spaces.
vim.api.nvim_exec([[
    hi EOLSpace ctermbg=238 guibg=#FF0000
    match EOLSpace /\s\+$/
]], false)

----------------------------------------------------------------------
-- Print out variable profile code
--
-- console.log('var: ' = var); // in JS
-- note("var: <$var>"); # in Raku
local function not_empty(s) return s ~= nil and s ~= '' end

_G.var_profiler = function()
    local lang_map = {
        ['javascript'] = 'JS',
        ['raku'] = 'Raku',
    }
    if lang_map[vim.bo.filetype] == nil then return end
    local output_map = {
        ['javascript'] = "console.log(`%s: ${%s}`);",
        ['raku'] = 'note("%s: <$%s>");',
    }
    local vars
    vim.ui.input(
        { prompt = string.format(
            'Enter %s var name(s): ', lang_map[vim.bo.filetype]
        )},
        function(input) vars = input end
    )
    if not_empty(vars) then
        for var in vars:gmatch('%S+') do
            local line = string.format(
                output_map[vim.bo.filetype], var, var
            )
            vim.api.nvim_put({ line }, 'l', false, true)
        end
    end
end

vim.keymap.set('n', '<leader>p', var_profiler)

----------------------------------------------------------------------
-- Remap keys.
vim.keymap.set('i', 'jj', '<Esc>')

_G.comment_toggler = function()
    local comment_mark_map = {
        ['javascript'] = "// ",
        ['lua'] = "-- ",
        ['raku'] = "# ",
    }
    if comment_mark_map[vim.bo.filetype] == nil then return end
    local comment_mark = comment_mark_map[vim.bo.filetype] or ""
    local comment_mark_length = string.len(comment_mark)
    local line = vim.api.nvim_get_current_line()
    local new_line
    if line:sub(1, comment_mark_length) == comment_mark then
        new_line = line:sub(comment_mark_length + 1)
    else
        new_line = comment_mark .. line:sub(1)
    end
    vim.api.nvim_set_current_line(new_line)
end

vim.keymap.set('n', '<leader>c', comment_toggler)
