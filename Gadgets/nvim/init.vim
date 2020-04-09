"// PLUGINS
call plug#begin(stdpath('data'). '/plugged')
Plug 'neoclide/coc.nvim', {'do': { -> coc#util#install()}}
Plug 'junegunn/goyo.vim'
Plug 'jiangmiao/auto-pairs'
Plug 'itchyny/lightline.vim'
Plug 'sakhnik/nvim-gdb', { 'do': ':!./install.sh \| UpdateRemotePlugins' }
call plug#end()

"// COC.NVIM STUFF
if filereadable($HOME."/.config/nvim/x-coc.loc")
	source /home/ayhon/.config/nvim/x-coc.loc
endif

"// AUTOCOMANDS
au BufNewFile,BufRead /*.rasi setf css
"au FileType cpp nnoremap <F5> :w<CR>:!clear && g++ -g -o % %< <CR>:split term://gdb -ex 'break resuelveCaso' %<CR>
au FileType cpp nnoremap <F5> :w<CR>:!clear && g++ -g -o program.out *.cpp <CR>:GdbStart gdb -q program.out<CR>
au FileType cpp nnoremap <space>y ggVG"+yVG"*y

"// SETTINGS
"colorscheme industry
highlight Pmenu ctermbg=8 cterm=bold ctermfg=white
set rnu nu "set hybrid numbering
set tabstop=4
set shiftwidth=4

"// KEYBINDINGS
nnoremap <space>g :Goyo 60%x60%<Return>
"nnoremap <space>y ggVG"+yVG"*y
inoremap <c-e> <c-c>^i//<c-c>'.i
