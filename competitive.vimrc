inoremap jj <Esc>
filetype on
filetype plugin on
filetype indent on
set background=dark
colorscheme torte
set t_Co=256
set expandtab
set cindent
set autoindent
set nu
set shiftwidth=4
set softtabstop=4
syntax on
map <F5> :<C-U>!g++ -O2 -DLOCAL -std=c++11 -Wall -Wextra -Wshadow -fsanitize=address -fsanitize=undefined %:r.cpp -o %:r<CR>
map <F4> :<C-U>!g++ -g -std=c++11 -Wall -Wextra -Wshadow %:r.cpp -o %:r<CR>
map <F9> :<C-U>!./%:r<CR>
map <F8> :<C-U>!gdb %:r<CR>
autocmd BufNewFile *.cpp -r ~/competitive/template.cpp
