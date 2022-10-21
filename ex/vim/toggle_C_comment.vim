" --------------------------------------------------------------------
" Toggle ｢/*⋯*/｣ style one line comments.

nnoremap <silent> <Plug>CStyleOneLine
  \ ^:if search('/\*.*\*/', 'c', line(".")) != 0<cr>
  \     :.s,/\* *\(.\{-}\) *\*/,\1,g<cr>
  \ :else<cr>
  \     :.s,\(\s*\)\(.*\)\(\s*\),\1/\* \2 \*/\3,g<cr>
  \ :endif<cr>
  \ :noh<cr>
\:call repeat#set("\<Plug>CStyleOneLine")<cr>
nmap ,cc <Plug>CStyleOneLine
