local o = vim.opt

o.number = true
o.relativenumber = true
o.colorcolumn = '70,80'
o.wildmenu = true

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
    "ThePrimeagen/vim-be-good",
})

require('onedark').setup { style = 'warmer' }
require('onedark').load()

vim.api.nvim_exec([[
    hi EOLSpace ctermbg=238 guibg=#333333
    match EOLSpace /\s\+$/
]], false)

local function notEmpty(s) return s ~= nil and s ~= '' end

local function varProfiler(lang, output)
    local vars
    vim.ui.input(
        { prompt = string.format('Enter %s var name(s): ', lang) },
        function(input) vars = input end
    )
    if notEmpty(vars) then
        for var in vars:gmatch('%S+') do
            local line = string.format(output, var, var)
            vim.api.nvim_put({ line }, 'l', false, true)
        end
    end
end

vim.keymap.set('n', 'Km',
    function() varProfiler('JS', "console.log('%s: ' + %s);") end
)

vim.keymap.set('n', 'Kn',
    function() varProfiler('Raku', 'note("%s: <$%s>");') end
)
