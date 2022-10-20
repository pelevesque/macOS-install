local o = vim.opt

o.number = true
o.wrap = true

require ('packer').startup(function()
    use 'wbthomason/packer.nvim'
    use 'navarasu/onedark.nvim'
end)

require('onedark').setup { style = 'warmer' }
require('onedark').load()
