""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" This .vimrc file is based on default configuration of spf13/spf13-vim, and
" highly optimized for tongsucn's daily development requirements.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

"_______________________________________________________________________________
" Configurations for Vundle, BEGIN.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Pre-requests.
set nocompatible
filetype off

" Set the runtime path to include Vundle and initialize.
set rtp+=~/.vim/bundle/Vundle.vim

" Plugins list begins.
call vundle#begin()

" Let Vundle manage Vundle and other dependencies, required.
Plugin 'VundleVim/Vundle.vim'
Plugin 'MarcWeber/vim-addon-mw-utils'
Plugin 'tomtom/tlib_vim'

" Visual optimization.
Plugin 'altercation/vim-colors-solarized' " Solarized scheme.
Plugin 'bling/vim-bufferline'             " Add buffer info to status bar.
Plugin 'vim-airline/vim-airline'          " Vim Airline status bar.
Plugin 'vim-airline/vim-airline-themes'   " Themes for Airline.
Plugin 'osyo-manga/vim-over'              " Real-time high-light match when
                                          " typing substitution command.
Plugin 'mhinz/vim-signify'                " Version control info high-light.
Plugin 'rhysd/conflict-marker.vim'        " High-light git conflict markers.
Plugin 'luochen1990/rainbow'              " Colorize brackets.
Plugin 'spf13/vim-preview'                " Preview of Markdown etc.

" Functionality enhancement.
Plugin 'jiangmiao/auto-pairs'         " Brackets and quotes auto complete.
Plugin 'tpope/vim-fugitive'           " Git operations integration.
Plugin 'ctrlpvim/ctrlp.vim'           " Ctrl+P to find files etc.
Plugin 'tacahiroy/ctrlp-funky'        " Enhancement for ctrlp.
Plugin 'easymotion/vim-easymotion'    " Fast cursor movements.
Plugin 'vim-scripts/restore_view.vim' " Restoring cursor position after restart.
Plugin 'tpope/vim-commentary'         " Commenting out blocks.

" AutoComplete.
Plugin 'Shougo/neocomplete.vim.git'
Plugin 'Shougo/neosnippet'
Plugin 'Shougo/neosnippet-snippets'
Plugin 'honza/vim-snippets'

" Syntax checker.
Plugin 'w0rp/ale'

" Language specific plugins.
" Text writing.
Plugin 'kana/vim-textobj-user'
Plugin 'kana/vim-textobj-indent'
Plugin 'reedes/vim-litecorrect'
Plugin 'reedes/vim-textobj-sentence'
Plugin 'reedes/vim-textobj-quote'
Plugin 'reedes/vim-wordy'
Plugin 'godlygeek/tabular'           " Quick formatting tabular.
Plugin 'tpope/vim-markdown'          " Markdown support.

" Python
Plugin 'yssource/python.vim' " Basic config., incl. high-light etc.
Plugin 'pythoncomplete'      " Semantatic enhancement.
Plugin 'nvie/vim-flake8'     " Static analytics.
Plugin 'python_match.vim'    " Enhance if-else's % motion in Python.

" Javascript
Plugin 'pangloss/vim-javascript' " Basic config. for JS.
Plugin 'briancollins/vim-jst'    " High-light and indenting for JST/EJS.
Plugin 'elzr/vim-json'           " JSON support.

" Haskell
Plugin 'travitch/hasksyn'
Plugin 'dag/vim2hs'
Plugin 'Twinside/vim-haskellConceal'
Plugin 'Twinside/vim-haskellFold'
Plugin 'lukerandall/haskellmode-vim'
Plugin 'eagletmt/neco-ghc'
Plugin 'eagletmt/ghcmod-vim'
Plugin 'Shougo/vimproc.vim'
Plugin 'adinapoli/cumino'
Plugin 'bitc/vim-hdevtools'

" Golang
Plugin 'fatih/vim-go'

" Rustlang
Plugin 'rust-lang/rust.vim'

" Plugins list ends.
call vundle#end()
filetype plugin indent on
"_______________________________________________________________________________
" Configurations for Vundle, END.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


"_______________________________________________________________________________
" General non-plugin configurations, BEGIN.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Visual configurations.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set background=dark             " Assume dark background.
set colorcolumn=80,100          " Set visual ruler.
set cursorline                  " High-light line where cursor locates.
set cursorcolumn                " High-light column where cursor locates.
set showmode                    " Always display current mode.
set number                      " Enable line number.
highlight clear SignColumn      " Sign-column should match background.
highlight clear LineNr          " Line number row have same background color.
highlight ColorColumn ctermbg=0 " Set ruler's color.
set showmatch                   " Show matched brackets.
set linespace=0                 " No extra spaces between rows.
set hlsearch                    " High-light search terms.
set winminheight=0              " Windows can be 0 line high.
set list                        " Make whitespace visible.
set listchars=tab:›\ ,trail:•,extends:#,nbsp:. " Show problematic whitespace.

" Use solarized color scheme.
if filereadable(expand("~/.vim/bundle/vim-colors-solarized/colors/solarized.vim"))
    let g:solarized_termtrans=1
    let g:solarized_contrast="normal"
    let g:solarized_visibility="normal"
    color solarized
endif

" Show ruler.
if has('cmdline_info')
    set ruler                                          " Show ruler.
    set rulerformat=%30(%=\:b%n%y%m%r%w\ %l,%c%V\ %P%) " A ruler on steroids.
    set showcmd  " Show partial commands in status line and selected
                 " characters/lines in visual mode
endif

" Show status line.
if has('statusline')
    set laststatus=2
    set statusline=%<%f\                     " Filename.
    set statusline+=%w%h%m%r                 " Options.
    set statusline+=\ [%{&ff}/%Y]            " Filetype.
    set statusline+=\ [%{getcwd()}]          " Current dir.
    set statusline+=%=%-14.(%l,%c%V%)\ %p%%  " Right aligned file nav info.
endif


" Formatting configurations.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
augroup restoreCursor
    autocmd!
    autocmd BufWinEnter * call RestoreCursor()
augroup END

set backspace=indent,eol,start " Backspace for dummies.
set autoindent                 " Enable automatically indenting.
set shiftwidth=4               " Set tab's width to 4.
set tabstop=4                  " Indent size 4.
set softtabstop=4              " Backspace is able to delete indent.
set expandtab                  " Convert tab to space.
set nojoinspaces               " Prevent inserting 2 spaces when joining lines.

" Remove trailing whitespaces and ^M chars.
autocmd FileType c,cpp,java,go,php,javascript,puppet,python,rust,twig,xml,yml,perl,sql autocmd BufWritePre <buffer> call StripTrailingWhitespace()

" Language-oriented formatting configurations.
autocmd FileType go autocmd BufWritePre <buffer> Fmt
autocmd BufNewFile,BufRead *.html.twig set filetype=html.twig
autocmd FileType haskell,ruby,yml setlocal expandtab shiftwidth=2 softtabstop=2

" Workaround vim-commentary for Haskell.
autocmd FileType haskell setlocal commentstring=--\ %s

" Workaround broken color highlighting in Haskell.
autocmd FileType haskell,rust setlocal nospell


" Interactive configurations.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
set mouse=a                    " Automatically enable mouse usage.
set mousehide                  " Hide mouse cursor while typing.
set shortmess+=filmnrxoOtT     " Avoid 'hit enter'.
set virtualedit=onemore        " Allow for cursor beyond last character.
set hidden                     " Allow buffer switch without saving.
set splitright                 " Put new vsplit windows to the right of current.
set splitbelow                 " Put new split windows to the bottom of current.
set incsearch                  " Find as you type search.
set ignorecase                 " Case insensitive search.
set smartcase                  " Case sensitive when uc present.
set scrolljump=5               " Lines to scroll when cursor leaves screen.
set scrolloff=3                " Minimum lines to keep above and below cursor.
set foldenable                 " Auto fold code.
set pastetoggle=<F12>          " Use <F12> to enable paste mode.
set wildmenu                   " Show list instead of just completing.
set wildmode=list:longest,full " Command <Tab> completion, list matches, then
                               " longest common part, then all.
set whichwrap=b,s,h,l,<,>,[,]  " Backspace and cursor keys wrap too.


" Key mapping configurations.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Switch leader key to ,.
let mapleader = ','

" Windows switching.
map <C-J> <C-W>j<C-W>_
map <C-K> <C-W>k<C-W>_
map <C-L> <C-W>l<C-W>_
map <C-H> <C-W>h<C-W>_

" Stupid shift key fixess
if has("user_commands")
    command! -bang -nargs=* -complete=file E e<bang> <args>
    command! -bang -nargs=* -complete=file W w<bang> <args>
    command! -bang -nargs=* -complete=file Wq wq<bang> <args>
    command! -bang -nargs=* -complete=file WQ wq<bang> <args>
    command! -bang Wa wa<bang>
    command! -bang WA wa<bang>
    command! -bang Q q<bang>
    command! -bang QA qa<bang>
    command! -bang Qa qa<bang>
endif
cmap Tabe tabe

" Yank from the cursor to the end of the line, to be consistent with C and D.
nnoremap Y y$

" File content configurations.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
scriptencoding utf-8      " Set encoding to UTF-8.
filetype plugin indent on " Automatically detect file types.
syntax on                 " Enable syntax high-lighting.
set spell                 " Enable spell checking.
set iskeyword-=.           " Treat '.' as the end of a word.
set iskeyword-=#           " Treat '#' as the end of a word.
set iskeyword-=-           " Treat '-' as the end of a word.


" Working environment configurations.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Automatically change working directory to opened buffer.
autocmd BufEnter * if bufname("") !~ "^\[A-Za-z0-9\]*://" | lcd %:p:h | endif
set history=1000           " Enlarge history buffer.
set backup                 " Enable back up.
if has("persistent_undo")  " Check if persistent undo is available.
    set undofile           " Enable undo.
    set undolevels=1000    " Max. # of changes that can be undone.
    set undoreload=10000   " Max. # lines to save for undo on a buffer reload.
endif

"_______________________________________________________________________________
" General non-plugin configurations, END.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


"_______________________________________________________________________________
" Configurations for all plugins, BEGIN.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Golang
let g:go_highlight_functions = 1
let g:go_highlight_methods = 1
let g:go_highlight_structs = 1
let g:go_highlight_operators = 1
let g:go_highlight_build_constraints = 1
let g:go_fmt_command = "goimports"
au FileType go nmap <Leader>s <Plug>(go-implements)
au FileType go nmap <Leader>i <Plug>(go-info)
au FileType go nmap <Leader>e <Plug>(go-rename)
au FileType go nmap <leader>r <Plug>(go-run)
au FileType go nmap <leader>b <Plug>(go-build)
au FileType go nmap <leader>t <Plug>(go-test)
au FileType go nmap <Leader>gd <Plug>(go-doc)
au FileType go nmap <Leader>gv <Plug>(go-doc-vertical)
au FileType go nmap <leader>co <Plug>(go-coverage)

" ALE
if isdirectory(expand("~/.vim/bundle/ale/"))
    " Set linter.
    let g:ale_linters = {
        \ 'c': ['gcc', 'cppcheck', 'cpplint'],
        \ 'cpp': ['g++', 'cppcheck', 'cpplint'],
        \ 'python': ['flake8'],
        \ 'proto': ['proto-gen-lint'],
        \ 'go': ['gofmt', 'golint', 'go vet'],
        \ 'sh': ['shellcheck', 'shfmt'],
        \ }
    " Set fixer.
    " Shutdown ALE's completion.
    let g:ale_completion_enabled = 0
endif


" Plain text
augroup textobj_sentence
    autocmd!
    autocmd FileType markdown call textobj#sentence#init()
    autocmd FileType textile call textobj#sentence#init()
    autocmd FileType text call textobj#sentence#init()
augroup END
augroup textobj_quote
    autocmd!
    autocmd FileType markdown call textobj#quote#init()
    autocmd FileType textile call textobj#quote#init()
    autocmd FileType text call textobj#quote#init({'educate': 0})
augroup END

" Ctags
set tags=./tags;/,~/.vimtags
" Make tags placed in .git/tags file available in all levels of a repository
let gitroot = substitute(system('git rev-parse --show-toplevel'), '[\n\r]', '', 'g')
if gitroot != ''
    let &tags = &tags . ',' . gitroot . '/.git/tags'
endif

" Ctrlp
if isdirectory(expand("~/.vim/bundle/ctrlp.vim/"))
    let g:ctrlp_working_path_mode = 'ra'
    nnoremap <silent> <D-t> :CtrlP<CR>
    nnoremap <silent> <D-r> :CtrlPMRU<CR>
    let g:ctrlp_custom_ignore = {
        \ 'dir':  '\.git$\|\.hg$\|\.svn$',
        \ 'file': '\.exe$\|\.so$\|\.dll$\|\.pyc$' }

    if executable('ag')
        let s:ctrlp_fallback = 'ag %s --nocolor -l -g ""'
    elseif executable('ack-grep')
        let s:ctrlp_fallback = 'ack-grep %s --nocolor -f'
    elseif executable('ack')
        let s:ctrlp_fallback = 'ack %s --nocolor -f'
    else
        let s:ctrlp_fallback = 'find %s -type f'
    endif
    if exists("g:ctrlp_user_command")
        unlet g:ctrlp_user_command
    endif
    let g:ctrlp_user_command = {
        \ 'types': {
        \ 1: ['.git', 'cd %s && git ls-files . --cached --exclude-standard --others'],
        \ 2: ['.hg', 'hg --cwd %s locate -I .'],
        \ },
        \ 'fallback': s:ctrlp_fallback
        \ }

    if isdirectory(expand("~/.vim/bundle/ctrlp-funky/"))
        " CtrlP extensions
        let g:ctrlp_extensions = ['funky']

        "funky
        nnoremap <Leader>fu :CtrlPFunky<Cr>
    endif
endif

" Rainbow
if isdirectory(expand("~/.vim/bundle/rainbow/"))
    let g:rainbow_active = 1
endif

" Fugitive
if isdirectory(expand("~/.vim/bundle/vim-fugitive/"))
    nnoremap <silent> <leader>gs :Gstatus<CR>
    nnoremap <silent> <leader>gd :Gdiff<CR>
    nnoremap <silent> <leader>gc :Gcommit<CR>
    nnoremap <silent> <leader>gb :Gblame<CR>
    nnoremap <silent> <leader>gl :Glog<CR>
    nnoremap <silent> <leader>gp :Git push<CR>
    nnoremap <silent> <leader>gr :Gread<CR>
    nnoremap <silent> <leader>gw :Gwrite<CR>
    nnoremap <silent> <leader>ge :Gedit<CR>
    " Mnemonic _i_nteractive
    nnoremap <silent> <leader>gi :Git add -p %<CR>
    nnoremap <silent> <leader>gg :SignifyToggle<CR>
endif

" Airline
if isdirectory(expand("~/.vim/bundle/vim-airline-themes/"))
    if !exists('g:airline_theme')
        let g:airline_theme = 'molokai'
    endif
    if !exists('g:airline_powerline_fonts')
        " Use the default set of separators with a few customizations
        let g:airline_left_sep='›'  " Slightly fancier than '>'
        let g:airline_right_sep='‹' " Slightly fancier than '<'
    endif
endif

" Neocomplete
let g:acp_enableAtStartup = 0
let g:neocomplete#enable_at_startup = 1
let g:neocomplete#enable_smart_case = 1
let g:neocomplete#enable_auto_delimiter = 1
let g:neocomplete#max_list = 15
let g:neocomplete#force_overwrite_completefunc = 1


" Define dictionary.
let g:neocomplete#sources#dictionary#dictionaries = {
        \ 'default' : '',
        \ 'vimshell' : $HOME.'/.vimshell_hist',
        \ 'scheme' : $HOME.'/.gosh_completions'
        \ }

" Define keyword.
if !exists('g:neocomplete#keyword_patterns')
    let g:neocomplete#keyword_patterns = {}
endif
let g:neocomplete#keyword_patterns['default'] = '\h\w*'

" Plugin key-mappings {
    " These two lines conflict with the default digraph mapping of <C-K>
    imap <C-k> <Plug>(neosnippet_expand_or_jump)
    smap <C-k> <Plug>(neosnippet_expand_or_jump)
    " <C-k> Complete Snippet
    " <C-k> Jump to next snippet point
    imap <silent><expr><C-k> neosnippet#expandable() ?
        \ "\<Plug>(neosnippet_expand_or_jump)" : (pumvisible() ?
        \ "\<C-e>" : "\<Plug>(neosnippet_expand_or_jump)")
    smap <TAB> <Right><Plug>(neosnippet_jump_or_expand)

    inoremap <expr><C-g> neocomplete#undo_completion()
    inoremap <expr><C-l> neocomplete#complete_common_string()
    "inoremap <expr><CR> neocomplete#complete_common_string()

    " <CR>: close popup
    " <s-CR>: close popup and save indent.
    inoremap <expr><s-CR> pumvisible() ? neocomplete#smart_close_popup()."\<CR>" : "\<CR>"

    function! CleverCr()
        if pumvisible()
            if neosnippet#expandable()
                let exp = "\<Plug>(neosnippet_expand)"
                return exp . neocomplete#smart_close_popup()
            else
                return neocomplete#smart_close_popup()
            endif
        else
            return "\<CR>"
        endif
    endfunction

    " <CR> close popup and save indent or expand snippet
    imap <expr> <CR> CleverCr()
    " <C-h>, <BS>: close popup and delete backword char.
    inoremap <expr><BS> neocomplete#smart_close_popup()."\<C-h>"
    inoremap <expr><C-y> neocomplete#smart_close_popup()
    " <TAB>: completion.
    inoremap <expr><TAB> pumvisible() ? "\<C-n>" : "\<TAB>"
    inoremap <expr><S-TAB> pumvisible() ? "\<C-p>" : "\<TAB>"

    " Courtesy of Matteo Cavalleri

    function! CleverTab()
        if pumvisible()
            return "\<C-n>"
        endif
        let substr = strpart(getline('.'), 0, col('.') - 1)
        let substr = matchstr(substr, '[^ \t]*$')
        if strlen(substr) == 0
            " nothing to match on empty string
            return "\<Tab>"
        else
            " existing text matching
            if neosnippet#expandable_or_jumpable()
                return "\<Plug>(neosnippet_expand_or_jump)"
            else
                return neocomplete#start_manual_complete()
            endif
        endif
    endfunction

    imap <expr> <Tab> CleverTab()
" }

" Enable heavy omni completion.
if !exists('g:neocomplete#sources#omni#input_patterns')
    let g:neocomplete#sources#omni#input_patterns = {}
endif
let g:neocomplete#sources#omni#input_patterns.php = '[^. \t]->\h\w*\|\h\w*::'
let g:neocomplete#sources#omni#input_patterns.perl = '\h\w*->\h\w*\|\h\w*::'
let g:neocomplete#sources#omni#input_patterns.c = '[^.[:digit:] *\t]\%(\.\|->\)'
let g:neocomplete#sources#omni#input_patterns.cpp = '[^.[:digit:] *\t]\%(\.\|->\)\|\h\w*::'
let g:neocomplete#sources#omni#input_patterns.ruby = '[^. *\t]\.\h\w*\|\h\w*::'

"_______________________________________________________________________________
" Configurations for all plugins, END.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""


"_______________________________________________________________________________
" Functions, BEGIN.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Function for removing trailing whitespace.
function! StripTrailingWhitespace()
    " Preparation: save last search, and cursor position.
    let _s=@/
    let l = line(".")
    let c = col(".")
    " do the business:
    %s/\s\+$//e
    " Clean up: restore previous search history, and cursor position.
    let @/=_s
    call cursor(l, c)
endfunction

" Function for restoring cursor.
function! RestoreCursor()  " Function for recovering cursor position.
    if line("'\"") <= line("$")
        silent! normal! g`"
        return 1
    endif
endfunction

function! InitializeDirectories()
    let parent = $HOME
    let prefix = 'vim'
    let dir_list = {
        \ 'backup': 'backupdir',
        \ 'views': 'viewdir',
        \ 'swap': 'directory' }

    if has('persistent_undo')
        let dir_list['undo'] = 'undodir'
    endif

    let common_dir = parent . '/.' . prefix

    for [dirname, settingname] in items(dir_list)
        let directory = common_dir . dirname . '/'
        if exists("*mkdir")
            if !isdirectory(directory)
                call mkdir(directory)
            endif
        endif
        if !isdirectory(directory)
            echo "Warning: Unable to create backup directory: " . directory
            echo "Try: mkdir -p " . directory
        else
            let directory = substitute(directory, " ", "\\\\ ", "g")
            exec "set " . settingname . "=" . directory
        endif
    endfor
endfunction
call InitializeDirectories()

"_______________________________________________________________________________
" Functions, END.
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
