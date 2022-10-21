local o = vim.opt

o.number = true
o.wrap = true
o.colorcolumn = '70,80'

require ('packer').startup(function()
    use 'wbthomason/packer.nvim'
    use 'navarasu/onedark.nvim'
    use 'airblade/vim-gitgutter'

    -- lualine needs patched fonts installed.
    -- https://www.nerdfonts.com
    use 'nvim-lualine/lualine.nvim'
end)

require('onedark').setup { style = 'warmer' }
require('onedark').load()

require('lualine').setup()

vim.api.nvim_exec([[
    hi EOLSpace ctermbg=238 guibg=#333333
    match EOLSpace /\s\+$/
]], false)
