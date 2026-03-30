% QuantaQuest.cls
% -------------------------------------------------------------------
% QuantaQuest — Flexible book class (book-based)
% Maintenance notes:
% - This file is organized in “gold-standard” blocks: options → core
%   utilities → engines/fonts/math → layout → content features → UI/UX.
% - Keep package loading near the top of the block that uses it.
% - Keep public interfaces (commands/environments) grouped and documented.
% -------------------------------------------------------------------

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{QuantaQuest}[2025/12/20 v1.0 Flexible Class]

% ===================================================================
% 0. CLASS OPTIONS + BASE CLASS
% ===================================================================
% Pass any unknown options through to the base class.
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{book}}
\ProcessOptions\relax

% Baseline: book class with twoside by default.
% If user passes oneside, the base class typically respects user choice.
\LoadClass[a4paper, twoside]{book}

% ===================================================================
% 1. CORE PROGRAMMING UTILITIES (FOUNDATION)
% ===================================================================
% These are “infrastructure” packages used throughout the class:
% - etoolbox: robust conditionals and patching utilities
% - calc: arithmetic with lengths
\RequirePackage{etoolbox}
\RequirePackage{calc}

% ===================================================================
% 2. CORE GRAPHICS SUPPORT (MUST PRECEDE ANY \includegraphics USAGE)
% ===================================================================
\RequirePackage{graphicx}

% ===================================================================
% 3. DOCUMENT METADATA INTERFACE (BOOK-LEVEL IDENTIFIERS)
% ===================================================================
% These commands store “book identity” fields in \u... macros.
% Notes:
% - Keep these setters simple; avoid layout decisions inside them.
% - \@title, \@author, \@date are standard LaTeX title fields.
\DeclareDocumentCommand{\date}{m}{\newcommand{\udate}{#1}\renewcommand{\@date}{#1}}

\DeclareDocumentCommand{\title}{om}{
  \IfValueTF{#1}{\newcommand{\ushorttitle}{#1}}{\newcommand{\ushorttitle}{#2}}
  \newcommand{\utitle}{#2}
  \renewcommand{\@title}{#2}
  \newcommand{\@titleline}{{\Large\bfseries\utitle\par}\vspace*{0.2em}}
}
\DeclareDocumentCommand{\subtitle}{m}{\newcommand{\usubtitle}{#1}}

\DeclareDocumentCommand{\author}{m}{\newcommand{\uauthor}{#1}\renewcommand{\@author}{#1}}
\DeclareDocumentCommand{\affiliation}{m}{\newcommand{\uaffiliation}{#1}}
\DeclareDocumentCommand{\isbn}{m}{\newcommand{\uisbn}{#1}}
\DeclareDocumentCommand{\publisher}{m}{\newcommand{\upublisher}{#1}}
\DeclareDocumentCommand{\edition}{m}{\newcommand{\uedition}{#1}}
\DeclareDocumentCommand{\volume}{m}{\newcommand{\uvolume}{#1}}
\DeclareDocumentCommand{\revision}{m}{\newcommand{\urevision}{#1}}
\DeclareDocumentCommand{\website}{m}{\newcommand{\uwebsite}{#1}}

% ===================================================================
% 4. ENGINE, FONTS, MATH (XE/LUA STACK)
% ===================================================================
% Notes:
% - fontspec/unicode-math imply XeLaTeX or LuaLaTeX.
% - Keep math stack grouped and loaded once.
\RequirePackage{fontspec}
\RequirePackage{mathtools}
\RequirePackage[math-style=ISO,warnings-off={mathtools-colon, mathtools-overbracket}]{unicode-math}

% ===================================================================
% 5. TYPOGRAPHY GLOBALS (SPACING + MICRO-TYPOGRAPHY)
% ===================================================================
\RequirePackage{setspace}
% \RequirePackage{parskip}
% \RequirePackage{indentfirst}
\newlength{\globalparskip}
\setlength{\globalparskip}{\parskip}

\RequirePackage{microtype}
\RequirePackage{ragged2e}
\RequirePackage{csquotes}
\RequirePackage{lipsum}
% ===================================================================
% 6. COLOR PALETTE (PROJECT-WIDE BRAND COLORS)
% ===================================================================
\RequirePackage[x11names]{xcolor}
\definecolor{iRedOnLight}{RGB}{233, 21, 45} 
\definecolor{iOrangeOnLight}{RGB}{197, 83, 0} 
\definecolor{iYellowOnLight}{RGB}{161, 106, 0} 
\definecolor{iGreenOnLight}{RGB}{0, 137, 50} 
\definecolor{iMintOnLight}{RGB}{0, 133, 117} 
\definecolor{iTealOnLight}{RGB}{0, 129, 152} 
\definecolor{iCyanOnLight}{RGB}{0, 126, 174} 
\definecolor{iBlueOnLight}{RGB}{30, 110, 244} 
\definecolor{iIndigoOnLight}{RGB}{86, 74, 222} 
\definecolor{iPurpleOnLight}{RGB}{176, 47, 194} 
\definecolor{iPinkOnLight}{RGB}{231, 18, 77} 
\definecolor{iBrownOnLight}{RGB}{149, 109, 81} 
\definecolor{iGrayOnLight}{RGB}{108, 108, 112} 
\definecolor{iGrayBackgroundOnLight}{RGB}{235, 235, 240} 

\definecolor{iRedOnDark}{RGB}{255, 97, 101} 
\definecolor{iOrangeOnDark}{RGB}{255, 160, 86} 
\definecolor{iYellowOnDark}{RGB}{254, 223, 67} 
\definecolor{iGreenOnDark}{RGB}{74, 217, 104} 
\definecolor{iMintOnDark}{RGB}{84, 223, 203} 
\definecolor{iTealOnDark}{RGB}{59, 221, 236} 
\definecolor{iCyanOnDark}{RGB}{109, 217, 255} 
\definecolor{iBlueOnDark}{RGB}{92, 184, 255} 
\definecolor{iIndigoOnDark}{RGB}{167, 170, 250} 
\definecolor{iPurpleOnDark}{RGB}{234, 141, 255} 
\definecolor{iPinkOnDark}{RGB}{255, 138, 196} 
\definecolor{iBrownOnDark}{RGB}{219, 166, 121} 
\definecolor{iGrayOnDark}{RGB}{174, 174, 178} 
\definecolor{iGrayBackgroundOnDark}{RGB}{36, 36, 38} 

% ALMOND color 

\definecolor{tailwindalmond50}{HTML}{F8F3ED}
\definecolor{tailwindalmond100}{HTML}{EADDCA}
\definecolor{tailwindalmond200}{HTML}{DEC9AB}
\definecolor{tailwindalmond300}{HTML}{D0B48A}
\definecolor{tailwindalmond400}{HTML}{C39F69}
\definecolor{tailwindalmond500}{HTML}{B68A49}
\definecolor{tailwindalmond600}{HTML}{96723C}
\definecolor{tailwindalmond700}{HTML}{75592F}
\definecolor{tailwindalmond800}{HTML}{544021}
\definecolor{tailwindalmond900}{HTML}{332714}
\definecolor{tailwindalmond950}{HTML}{120E07}
% 

% OCHRE

\definecolor{tailwindochre50}{HTML}{FBF2E9}
\definecolor{tailwindochre100}{HTML}{F5DBC2}
\definecolor{tailwindochre200}{HTML}{EEC49B}
\definecolor{tailwindochre300}{HTML}{E7AD73}
\definecolor{tailwindochre400}{HTML}{E1964C}
\definecolor{tailwindochre500}{HTML}{CC7722}
\definecolor{tailwindochre600}{HTML}{B3691E}
\definecolor{tailwindochre700}{HTML}{8C5218}
\definecolor{tailwindochre800}{HTML}{643B11}
\definecolor{tailwindochre900}{HTML}{3D240A}
\definecolor{tailwindochre950}{HTML}{160D04}

\definecolor{tintsochre50}{HTML}{FDF2EA}
\definecolor{tintsochre100}{HTML}{FAE6D6}
\definecolor{tintsochre200}{HTML}{F7D9C1}

% red

\definecolor{tailwindred50}{HTML}{FFE6E6}
\definecolor{tailwindred100}{HTML}{FFB8B8}
\definecolor{tailwindred200}{HTML}{FF8A8A}
\definecolor{tailwindred300}{HTML}{FF5C5C}
\definecolor{tailwindred400}{HTML}{FF2E2E}
\definecolor{tailwindred500}{HTML}{FF0000}
\definecolor{tailwindred600}{HTML}{D10000}
\definecolor{tailwindred700}{HTML}{A30000}
\definecolor{tailwindred800}{HTML}{750000}
\definecolor{tailwindred900}{HTML}{470000}
\definecolor{tailwindred950}{HTML}{1A0000}

\definecolor{tintsred50}{HTML}{FFEEE7}
\definecolor{tintsred100}{HTML}{FFDDD0}
\definecolor{tintsred200}{HTML}{FFCCB8}

% viridian

\definecolor{tailwindviridian50}{HTML}{EEF7F4}
\definecolor{tailwindviridian100}{HTML}{CFE7E0}
\definecolor{tailwindviridian200}{HTML}{B0D8CC}
\definecolor{tailwindviridian300}{HTML}{92C9B8}
\definecolor{tailwindviridian400}{HTML}{73BAA3}
\definecolor{tailwindviridian500}{HTML}{54AB8F}
\definecolor{tailwindviridian600}{HTML}{40826D}
\definecolor{tailwindviridian700}{HTML}{366D5C}
\definecolor{tailwindviridian800}{HTML}{274F42}
\definecolor{tailwindviridian900}{HTML}{183028}
\definecolor{tailwindviridian950}{HTML}{08110E}

\definecolor{tintsviridian50}{HTML}{EDF3F1}
\definecolor{tintsviridian100}{HTML}{DCE8E3}
\definecolor{tintsviridian200}{HTML}{CADCD5}

% sky blue 

\definecolor{blue50}{HTML}{E9F6FB}
\definecolor{blue100}{HTML}{C2E6F5}
\definecolor{blue200}{HTML}{87CEEB}
\definecolor{blue300}{HTML}{73C7E7}
\definecolor{blue400}{HTML}{4CB7E1}
\definecolor{blue500}{HTML}{25A7DA}
\definecolor{blue600}{HTML}{1E89B3}
\definecolor{blue700}{HTML}{186B8C}
\definecolor{blue800}{HTML}{114D64}
\definecolor{blue900}{HTML}{0A2F3D}
\definecolor{blue950}{HTML}{041116}

\definecolor{tintsblue50}{HTML}{F5FBFD}
\definecolor{tintsblue100}{HTML}{EBF6FB}


% amaranth 

\definecolor{tailwindamaranth50}{HTML}{FAEBF3}
\definecolor{tailwindamaranth100}{HTML}{F0C7DD}
\definecolor{tailwindamaranth200}{HTML}{E6A3C7}
\definecolor{tailwindamaranth300}{HTML}{DC7FB1}
\definecolor{tailwindamaranth400}{HTML}{D25B9A}
\definecolor{tailwindamaranth500}{HTML}{C83784}
\definecolor{tailwindamaranth600}{HTML}{9F2B68}
\definecolor{tailwindamaranth700}{HTML}{802355}
\definecolor{tailwindamaranth800}{HTML}{5C193D}
\definecolor{tailwindamaranth900}{HTML}{380F25}
\definecolor{tailwindamaranth950}{HTML}{14050D}

\definecolor{tintsamaranth50}{HTML}{F8ECF0}
\definecolor{tintsamaranth100}{HTML}{F0D9E2}
\definecolor{tintsamaranth200}{HTML}{E8C6D4}

% vermillion - red

\definecolor{tailwindvermillion50}{HTML}{FFE9E6}
\definecolor{tailwindvermillion100}{HTML}{FFC1B8}
\definecolor{tailwindvermillion200}{HTML}{FF998A}
\definecolor{tailwindvermillion300}{HTML}{FF725C}
\definecolor{tailwindvermillion400}{HTML}{FF4A2E}
\definecolor{tailwindvermillion500}{HTML}{FF2400}
\definecolor{tailwindvermillion600}{HTML}{D11C00}
\definecolor{tailwindvermillion700}{HTML}{A31600}
\definecolor{tailwindvermillion800}{HTML}{751000}
\definecolor{tailwindvermillion900}{HTML}{470A00}
\definecolor{tailwindvermillion950}{HTML}{1A0300}

\definecolor{tintsvermillion50}{HTML}{FFEFEB}
\definecolor{tintsvermillion100}{HTML}{FFDFD7}
\definecolor{tintsvermillion200}{HTML}{FFCFC4}

% sapphire blue 

\definecolor{tailwindsapphire50}{HTML}{E7F0FD}
\definecolor{tailwindsapphire100}{HTML}{BDD5FA}
\definecolor{tailwindsapphire200}{HTML}{92BAF6}
\definecolor{tailwindsapphire300}{HTML}{68A0F3}
\definecolor{tailwindsapphire400}{HTML}{3E85EF}
\definecolor{tailwindsapphire500}{HTML}{136AEC}
\definecolor{tailwindsapphire600}{HTML}{0F52BA}
\definecolor{tailwindsapphire700}{HTML}{0C4497}
\definecolor{tailwindsapphire800}{HTML}{09316D}
\definecolor{tailwindsapphire900}{HTML}{051E42}
\definecolor{tailwindsapphire950}{HTML}{020B18}

\definecolor{tintssapphire50}{HTML}{EDEEF9}
\definecolor{tintssapphire100}{HTML}{DBDDF3}

% celadon - green

\definecolor{tailwindceladon50}{HTML}{EDF8ED}
\definecolor{tailwindceladon100}{HTML}{CBEBCB}
\definecolor{tailwindceladon200}{HTML}{AFE1AF}
\definecolor{tailwindceladon300}{HTML}{89D289}
\definecolor{tailwindceladon400}{HTML}{67C567}
\definecolor{tailwindceladon500}{HTML}{46B946}
\definecolor{tailwindceladon600}{HTML}{3A983A}
\definecolor{tailwindceladon700}{HTML}{2D762D}
\definecolor{tailwindceladon800}{HTML}{205520}
\definecolor{tailwindceladon900}{HTML}{143414}
\definecolor{tailwindceladon950}{HTML}{071207}

% platinum - gray

\definecolor{tailwindplatinum50}{HTML}{F3F2F2}
\definecolor{tailwindplatinum100}{HTML}{E5E4E2}
\definecolor{tailwindplatinum200}{HTML}{C7C5C1}
\definecolor{tailwindplatinum300}{HTML}{B1AFA9}
\definecolor{tailwindplatinum400}{HTML}{9C9891}
\definecolor{tailwindplatinum500}{HTML}{868279}
\definecolor{tailwindplatinum600}{HTML}{6E6A63}
\definecolor{tailwindplatinum700}{HTML}{56534E}
\definecolor{tailwindplatinum800}{HTML}{3E3C38}
\definecolor{tailwindplatinum900}{HTML}{252422}
\definecolor{tailwindplatinum950}{HTML}{0D0D0C}



%===================================================================
% 7. TABLES + CAPTIONS (STRUCTURED DATA PRESENTATION)
% ===================================================================
\RequirePackage{booktabs}
\RequirePackage{tabularx}
\newcolumntype{C}{>{\centering\arraybackslash}X}
\newcolumntype{L}{>{\raggedright\arraybackslash}X}
\newcolumntype{R}{>{\raggedleft\arraybackslash}X}
\newcolumntype{D}[1]{>{\centering\arraybackslash}p{#1}}
\NewDocumentCommand{\ra}{m}{\renewcommand{\arraystretch}{#1}}

\RequirePackage[font=small,labelfont=bf,labelsep=endash]{caption}
\DeclareCaptionStyle{marginfigure}{font=small,labelfont=bf,labelsep=endash}
\DeclareCaptionStyle{sidecaption}{font=small,labelfont=bf,labelsep=endash}
\DeclareCaptionStyle{widefigure}{font=small,labelfont=bf,labelsep=endash}
\DeclareCaptionStyle{margintable}{font=small,labelfont=bf,labelsep=endash}
\DeclareCaptionStyle{widetable}{font=small,labelfont=bf,labelsep=endash}

%------------------------------------------------------------
% LISTS
%------------------------------------------------------------
\RequirePackage{enumitem}
\setlist{nosep}
\setlist[itemize,3]{label={$\circ$}}
\setlist[itemize,4]{label={\textasteriskcentered}}

% ===================================================================
% 8. BOXES, HIGHLIGHTS, CALLOUTS, AND TIKZ-ASSISTED UI COMPONENTS
% ===================================================================
\RequirePackage{minted}
\RequirePackage{tcolorbox}
\tcbuselibrary{skins, xparse, breakable, minted}

\RequirePackage{fontawesome5}

% highlights
\NewTCBox{\highlight}{O{iYellowOnDark}}{on line, size=minimal, colback=#1}

% keypoints
\NewTColorBox{keypoints}{ +O{} }{
  enhanced,
  breakable,
%   check odd page,
  toggle left and right,
  grow to right by=\marginparsep+\marginparwidth,
  toggle enlargement, % This automatically handles the flip on even/odd pages
%   if odd page={grow to right by=\marginparsep+\marginparwidth}{grow to left by=\marginparsep+\marginparwidth},
  frame hidden,
  % sharp corners,
  fontupper=\sffamily\fontseries{sc}\selectfont,
  fonttitle=\sffamily\fontseries{sc}\selectfont,
  % colframe=iRedOnLight,
  colback=tailwindvermillion50,
  coltitle=tailwindvermillion600,  
  title={\textbf{KEY POINTS}},
  detach title,
  before upper={\tcbtitle \quad}, %nếu cần thì thêm \parskip=\globalparskip
  #1
}
 
% term box
\NewTotalTColorBox{\termbox}{+O{} +m}{
  enhanced,
  frame hidden,
  fontupper=\sffamily\fontseries{sc}\selectfont\scriptsize,
%   before upper=\noindent\justifying, 
  colback=tailwindochre50,
%   colback=DarkOrange1!10,
%   colupper=DarkOrange4,
  width=\marginparwidth,
%   halign=left,
  nobeforeafter,
  boxsep=3pt,
  left=2pt, right=2pt, top=2pt, bottom=2pt,
  #1
}{\makebox[1.2em] {\textcolor{tailwindochre700}{\faSearchPlus}} #2}

\NewDocumentCommand{\term}{ +O{} +m !O{0pt} }{%
  \marginnote{\termbox[#1]{#2}}[#3]%
}

% connection box
\NewTotalTColorBox{\connectionbox}{+O{} +m}{
  enhanced,
  frame hidden,
  fontupper=\sffamily\fontseries{sc}\selectfont\scriptsize,
%   before upper=\noindent\justifying, 
%   colback=Blue1!10,
%   colupper=Blue4,
  colback=tailwindsapphire50, 
  width=\marginparwidth,
%   halign=left,
  nobeforeafter,
  boxsep=3pt,
  left=2pt, right=2pt, top=2pt, bottom=2pt,
  #1
}{\makebox[1.2em] {\textcolor{tailwindsapphire700}{\faCodeBranch}} #2}

\NewDocumentCommand{\connection}{ +O{} +m !O{0pt} }{%
  \marginnote{\connectionbox[#1]{#2}}[#3]%
}

% quicknote box
% Usage: \quicknote{Your note}
% Usage: \quicknote[2cm]{Note shifted down by 2cm}

% quicknote 
\NewTotalTColorBox{\quicknotebox}{+O{} +m}{
  enhanced,
  frame hidden,
  fontupper=\sffamily\fontseries{sc}\selectfont\scriptsize,
%   before upper=\noindent\justifying, 
  colback=tailwindceladon50,
%   colupper=Green4,
  width=\marginparwidth,
%   halign=left,
  nobeforeafter,
  boxsep=3pt,
  left=2pt, right=2pt, top=2pt, bottom=2pt,
  #1
}{\makebox[1.2em] {\textcolor{tailwindceladon700}{\faPlayCircle[regular]}} #2}

\NewDocumentCommand{\quicknote}{ +O{} +m !O{0pt} }{%
  \marginnote{\quicknotebox[#1]{#2}}[#3]%
}

% remark box
\NewTColorBox[auto counter,number within=section]{remark}{+!O{} +!O{}}{
  enhanced,
  % frame hidden,
  bottomrule=0pt,leftrule=0pt,rightrule=0pt,
  fonttitle=\sffamily\fontseries{sc}\selectfont\small,
  fontupper=\sffamily\fontseries{sc}\selectfont\small,
  colback=tintsviridian50,
%   colframe=iPinkOnLight!75!iGrayBackgroundOnDark,
  colframe=tintsviridian100,
  coltitle=tailwindviridian900,
  toptitle=2pt, bottomtitle=2pt, lefttitle=5pt, righttitle=5pt,
%   before upper=\RaggedRight,
  left=5pt, right=5pt, top=5pt, bottom=5pt,
  title={\makebox[1.2em] {\faEdit} Remark \thetcbcounter \hfill \textit{#1} \hfill \phantom{\makebox[1.2em]{\faEdit} Remark \thetcbcounter}},
  % attach boxed title to top left={yshift*=-\tcboxedtitleheight},
  #2
}

% example box

\NewTColorBox[auto counter, number within=section]{example}{+!O{} +!O{}}{
    enhanced,
    % frame hidden,
    % boxsep=0pt,
    boxrule=0pt,
    toprule=3pt,
    titlerule=-1pt, 
    toptitle=2pt, bottomtitle=2pt, lefttitle=5pt, righttitle=5pt,
    left=5pt, right=5pt, top=5pt, bottom=5pt,
    % bottomtitle=2pt,
    % boxrule=0pt,
    % toprule=2pt,
    colframe=tintsamaranth200, 
    colback=tintsamaranth50,
    % sharp corners,
    % 1. Cấu hình tiêu đề (Standard Title)
    colbacktitle=tintsamaranth100,
    coltitle=tailwindamaranth800,
    fontupper=\sffamily\fontseries{sc}\selectfont\small,
    fonttitle=\sffamily\fontseries{sc}\selectfont\small,
    % 2. CĂN GIỮA CHUYÊN NGHIỆP
    halign title=center, 
    lefttitle=3.5cm,   % Chừa chỗ cho khối tím (Label)
    righttitle=0cm,  % BẮT BUỘC: Phải bằng bên trái để chữ nằm đúng giữa hộp
    % 3. Nội dung tiêu đề
    % title={#1},        % Không để #2 vào trong overlay nữa!
    % Use \vphantom if the title is empty to maintain bar height
    % title={\IfValueTF{#1}{#1}{\vphantom{Bg}}},      % 4. Vẽ khối trang trí bên trái
    title=#1\vphantom{Bg},
    overlay={
        \fill[tintsamaranth200]  
            [rounded corners] ([yshift=1mm]title.north west) --  
            ([xshift=3.5cm, yshift=1mm]title.north west) -- 
            ([xshift=2.7cm]title.south west) -- 
            (title.south west) -- cycle ;
        \node[anchor=west, text=tailwindamaranth900, font=\sffamily\fontseries{sc}\selectfont\small] 
            at ([xshift=0pt, yshift=1pt]title.west) {\makebox[1.2em] {\faLightbulb} Example \thetcbcounter};
    },
    #2
}


% box bài tập
% problem box
\NewTColorBox[auto counter,number within=section]{problem}{+!O{} +!O{}}{
  enhanced,
  % frame hidden,
  fonttitle=\sffamily\fontseries{sc}\selectfont\small,
  fontupper=\sffamily\fontseries{sc}\selectfont\small,
  colback=tailwindalmond50,
  colframe=tailwindalmond100,
  coltitle=tailwindalmond900,
  boxrule=0pt,
  toptitle=2pt, bottomtitle=2pt, lefttitle=5pt, righttitle=5pt,
%   before upper=\RaggedRight,
  left=5pt, right=5pt, top=5pt, bottom=5pt,
  title={\makebox[1.2em] {\faToggleOn} Problem \thetcbcounter \hfill #1 \hfill \phantom{\makebox[1.2em]{\faToggleOn}}},
  % attach boxed title to top left={yshift*=-\tcboxedtitleheight},
  #2
}




% ===================================================================
% 9. GENERAL-PURPOSE ENVIRONMENTS (ASIDE, QUOTE, TEXTBOX, WIDE TEXT)
% ===================================================================
\RequirePackage[strict]{changepage}

\NewDocumentCommand{\newthought}{m}{{\scshape #1}}

% usage: \begin{aside}[heading]...\end{aside}
\NewDocumentEnvironment{aside}{ O{Aside:} }
  { \par\sffamily\textbf{#1}\space }
  { \normalfont\par\ }

% usage: \begin{textbox}[colour]...\end{textbox}
\NewDocumentEnvironment{textbox}{ O{lightgray} }
  { \begin{colbox}[backgroundcolor=#1] }
  { \end{colbox} }

% Redefine quote as a symmetric narrow block.
\RenewDocumentEnvironment{quote}{ }
  { \begin{adjustwidth}{0.1\textwidth}{0.1\textwidth} }
  { \end{adjustwidth} }

% Wide text spans into the margin note area on the outside.
\NewDocumentEnvironment{widetext}{}{
    \begin{adjustwidth}{0mm}{-\marginparwidth-\marginparsep}
}{\end{adjustwidth}}

% ===================================================================
% 10. FULL-WIDTH AREAS + TWO-COLUMN EXERCISES
% ===================================================================
\RequirePackage{multicol}
\RequirePackage[twosidemode, needspace=3mm, outermargin=-\marginparsep-\marginparwidth]{fullwidth}
\newcommand{\rulethick}{\hrule height 1pt \vspace{2mm}}

% usage: \begin{problems}[heading]\item...\end{problems}
\newenvironment{problems}[1][Exercises:]{
    \begin{fullwidth}[width=\linewidth+\marginparsep+\marginparwidth]
    \rulethick\vspace*{-3mm}
    \setlist[enumerate,1]{label=(\thechapter.\arabic*)}
    \setlist[enumerate,2]{label=(\alph*)}
    \section*{#1}
    \begin{multicols}{2}\begin{enumerate}
  }{
    \end{enumerate}\end{multicols}\end{fullwidth}
  }

% ===================================================================
% 11. SPECIAL PAGES (HALF TITLE, BLANK, ART)
% ===================================================================
% usage: \halftitlepage[custom-title]
\NewDocumentCommand{\halftitlepage}{o}{%
  \IfValueTF{#1}{\def\@halftitletext{#1}}{\def\@halftitletext{\utitle}}%
  \clearpage\thispagestyle{empty}\null\vspace{0.3\textheight}
  {\centering\huge\sffamily\@halftitletext\par}
  \clearpage
}

% usage: \blankpage[custom-text]
\NewDocumentCommand{\blankpage}{O{This page left blank intentionally}}{
  \clearpage\thispagestyle{empty}\null\vspace{0.3\textheight}
  {\centering\textit{#1}\par}
  \clearpage
}

% usage: \artpage[width]{image-file}[caption]
\NewDocumentCommand{\artpage}{O{\linewidth}mo}{%
  \IfValueTF{#3}{\def\@artpagetext{\par#3}}{\let\@artpagetext\relax}%
  \clearpage\thispagestyle{empty}\null\vfill\includegraphics[width=#1]{#2}\@artpagetext\vfill\null\clearpage
}

% ===================================================================
% 12. BIBLIOGRAPHY (NATBIB WORKFLOW)
% ===================================================================
\bibliographystyle{naturemag}
\usepackage[square,numbers,comma,sort&compress]{natbib}
\RequirePackage[nottoc]{tocbibind}

% Print bibliography from a given .bib base name.
\DeclareDocumentCommand{\printbibliography}{m}{
  \clearpage
  \begingroup
  \small\twocolumn
  \bibliography{#1}
  \endgroup
}

% ===================================================================
% 13. MARGIN + SIDE NOTES
% ===================================================================
\RequirePackage{sidenotes}
% Convert footnotes to sidenotes
\NewCommandCopy{\oldfootnote}{\footnote}
\RenewCommandCopy{\footnote}{\sidenote}

\RequirePackage{marginnote}
\NewCommandCopy{\oldmarginnote}{\marginnote}

% Force margin notes to follow normal text alignment.
\renewcommand*{\raggedleftmarginnote}{}
\renewcommand*{\raggedrightmarginnote}{}

% usage: \marginbox{...}
\NewDocumentCommand{\marginbox}{ m }
  { \oldmarginnote{\begin{colbox}\footnotesize#1\end{colbox}}}

% ===================================================================
% 14. LOCAL TOC + MARGIN TOC (ETOC)
% ===================================================================
\RequirePackage{etoc}

% Chapter-local TOC (sections only).
\NewDocumentCommand{\localtoc}{}{%
  \begin{tcolorbox}[
    enhanced,
    frame hidden,
    colback=white, % Or use a light color to match your theme
    sharp corners,
    boxsep=0pt, left=0pt, right=0pt, % Removes internal padding
    toggle left and right,
    % The magic math to expand into the margin parsep (5mm) + width (25mm)
    grow to right by=\dimexpr\marginparsep+\marginparwidth\relax,
    toggle enlargement,
  ]
  \begingroup
    \etocsettocstyle{}{} % Removes default etoc headers
    \etocsetnexttocdepth{subsection}

    \etocsetstyle{section}
      {}
      {}
      {%
        \sffamily\fontseries{sc}\selectfont\ % Consistent with your scientific header style
        \textcolor{tailwindvermillion600}{\bfseries\etocnumber} % Matches your red chapter theme
        \hspace*{2mm}
        \etocname
        \nobreak
        \hspace{5pt}\dotfill\hspace{5pt}
        \nobreak
        \etocpage
        \par\vspace*{1mm}
      }
      {}

    \etocsetstyle{subsection}
      {}
      {}
      {%
        \sffamily\fontseries{sc}\selectfont % Consistent with your scientific header style
        \hspace*{2mm}
        \textcolor{tailwindvermillion600}{\bfseries\etocnumber} % Matches your red chapter theme
        \hspace*{2mm}
        \etocname
        \nobreak
        \hspace{5pt}\dotfill\hspace{5pt}
        \nobreak
        \etocpage
        \par\vspace*{1mm}
      }
      {}
    \localtableofcontents
  \endgroup
  \end{tcolorbox}
}

% \NewDocumentCommand{\localtoc}{}{%
%   \begingroup
%     \etocsettocstyle{}{}
%     \etocsetnexttocdepth{section}

%     \etocsetstyle{section}
%       {}
%       {}
%       {%
%         \bfseries\small
%         \etocnumber
%         \hspace*{2mm}
%         \etocname
%         \nobreak
%         \hspace{5pt}\dotfill\hspace{5pt}
%         \nobreak
%         \etocpage
%         \par\vspace*{1mm}
%       }
%       {}
%     \localtableofcontents
%   \endgroup
% }

% Margin mini-TOC vertical shift control.
\newlength{\mtocshift}
\setlength{\mtocshift}{0mm}

% usage: \margintoc[vertical-shift]
\NewDocumentCommand{\margintoc}{ O{\mtocshift} }{
  \begingroup
    \etocsettocstyle{}{}
    \etocsetnexttocdepth{section}

    \etocsetstyle{section}
      {\noindent\leftskip 7mm \parindent -7mm}
      {}
      {%
        \bfseries\small\etocnumber\hspace*{2mm}\etocname
        \nobreak\hfill\nobreak\etocpage\par\vspace*{1mm}%
      }
      {}

    \marginnote{\localtableofcontents}[#1]
  \endgroup
}

% ===================================================================
% 15. FRONT/MAIN/BACK MATTER BEHAVIOR (HOOKS)
% ===================================================================
\RequirePackage{titlesec}

\AddToHook{cmd/frontmatter/after}{%
  \@openrightfalse
  \setlayout{extranarrow}%
  \titleformat{\chapter}[display]
  {\vspace*{-5mm}\sffamily}
  {\large\bfseries\chaptername\ \thechapter}
  {0mm}
  {\bfseries\Huge}
  [\vspace*{-5mm}]
}

\AddToHook{cmd/mainmatter/after}{
  \@openrighttrue
  \setlayout{default}
  \pagestyle{fancy-chapter}
\titleformat{\chapter}[block]{}{}{0pt}{%
  \begin{tcolorbox}[
    enhanced,
    colframe=tailwindvermillion600,
    colback=white,
    sharp corners,
    toggle left and right,
    grow to right by=\marginparsep+\marginparwidth,
    toggle enlargement, 
    boxrule=1pt,
    top=15pt, bottom=15pt,
    halign=center, valign=center,
    % left=10pt,
    fonttitle=\sffamily\fontseries{sc}\selectfont\Large,
    fontupper=\sffamily\bfseries\Huge, 
    coltitle=tailwindvermillion600, % Ensures the "Chapter X" text is black
    title={\chaptername\ \thechapter},
    attach boxed title to top left={xshift=15pt, yshift=-5mm},
    boxed title style={colback=white, colframe=tailwindvermillion900, boxrule=1pt, sharp corners, boxsep=5pt}
  ]
    % \centering\sffamily\bfseries\Huge\hyperlink{maintoc}
    \hyperlink{maintoc}
    }
    [\end{tcolorbox}]

   \titlespacing*{\chapter}{0pt}{-10mm}{15mm}
}
%   Define the Chapter Heading Style with tcolorbox
% Đảm bảo nạp thư viện cần thiết cho tcolorbox
%   \titleformat{\chapter}[block]
%     {\sffamily}
%     {}
%     {0pt}
%     {
%       \begin{tcolorbox}[
%         enhanced,
%         % check odd page, % Bật tính năng kiểm tra trang chẵn/lẻ
%         % Tự động giãn ra vùng margin dựa trên trang chẵn hay lẻ
%         toggle left and right,
%         grow to right by=\marginparsep+\marginparwidth,
%         toggle enlargement, 
%         % Cấu hình khung
%         colback=white,
%         colframe=iGrayOnLight,
%         arc=0pt,
%         outer arc=0pt,
%         boxrule=1pt,
%         left=15pt, right=15pt, top=20pt, bottom=20pt,
%         % Vẽ nhãn "Chapter X" đè lên khung
%         overlay={
%           \node[
%             fill=white, 
%             inner xsep=5pt, 
%             anchor=west, 
%             font=\sffamily\bfseries\selectfont\Large,
%           ] at ([xshift=15pt, yshift=-2pt]frame.north west) {\chaptername\ \thechapter};
%         }
%       ]
%       \centering\bfseries\Huge\hyperlink{maintoc}
%     }
%     [\end{tcolorbox}]
%   \titlespacing*{\chapter}{0pt}{-10mm}{15mm}
% }

\AddToHook{cmd/appendix/after}{
  \@openrighttrue
  \RenewDocumentCommand{\chaptername}{}{Appendix}
  \RenewDocumentCommand{\thechapter}{}{\Alph{chapter}}
}

\AddToHook{cmd/backmatter/after}{
  \@openrightfalse
  \bookmarksetup{startatroot}
  \setlayout{extrawide}
  \pagestyle{fancy-pagenum}
}

% ===================================================================
% 16. HEADINGS (PART/CHAPTER/SECTION)
% ===================================================================


% Part appearance.
\titleformat{\part}[display]
  {\centering\sffamily}
  {\LARGE\bfseries\partname\ \thepart}
  {0mm}
  {\bfseries\fontsize{38}{40}\selectfont}

\NewCommandCopy{\oldpart}{\part}

% Part redefinition:
% - Starred: print title only (no layout switch)
% - Unstarred: temporarily apply extranarrow layout around the part heading
\DeclareDocumentCommand{\part}{s o m}{%
  \IfBooleanTF{#1}
    { \oldpart*{#3} }
    {
      \setlayout{extranarrow}
      \IfValueTF{#2}{\oldpart[#2]{#3}}{\oldpart{#3}}
      \setlayout{default}
    }
}

% Back-of-book special part wrapper.
\DeclareDocumentEnvironment{partback}{o m}
  {
    \setlayout{extranarrow}
    \@openrightfalse
    \IfValueTF{#1}{\oldpart*[#1]{#2}}{\oldpart*{#2}}
    \thispagestyle{empty}
  }
  {
    \@openrighttrue
    \setlayout{default}
  }

% Keep a handle to the main ToC command for hyperlinks.
\NewCommandCopy{\maintoc}{\tableofcontents}

% Chapter appearance.
% \titleformat{\chapter}[display]
%   {\vspace*{-5mm}\sffamily}
%   {\large\bfseries\chaptername\ \thechapter}
%   {0mm}
%   {\bfseries\Huge}
%   [\vspace*{-5mm}]

% \titleformat{\chapter}[frame]
%   {\sffamily}
%   {\filright\large\bfseries\enspace\chaptername\thechapter\enspace}
%   {8pt}
%   {\bfseries\LARGE\filcenter\hyperlink{maintoc}}

% \titlespacing*{\chapter}{0pt}{-5mm}{10mm}

\titleformat{\section}{\sffamily\fontseries{bsc}\Large}{\hyperlink{localtoc\thechapter}\thesection}{0.75em}{\hyperlink{localtoc\thechapter}} % nếu cần upper case thì bổ sung thêm {\hyperlink{localtoc\thechapter}{\MakeUppercase{#1}}}
% \titleformat*{\subsection}{\sffamily\bfseries\large}

\titleformat{\subsection}{\sffamily\fontseries{bsc}\large}{\hyperlink{localtoc\thechapter}\thesubsection}{0.75em}{\hyperlink{localtoc\thechapter}}

% ===================================================================
% 17. SEPARATORS / RULES
% ===================================================================
\NewDocumentCommand{\widerule}{ O{darkgray} }{
  \par\textcolor{#1}{\rule{\linewidth}{1pt}}\par
}

% ===================================================================
% 18. PAGE GEOMETRY (DEFAULT + SWITCHABLE LAYOUTS)
% ===================================================================
\RequirePackage[a4paper]{geometry}
\geometry{
	includeall, 
	top=15mm,              
	bottom=15mm,           
	inner=20mm,            
	outer=15mm,            
	headheight=16pt,    
	marginparsep=5mm,      
	marginparwidth=55mm,    
}

% Layout switching helper:
% - extrawide: wider text, no margin notes
% - extranarrow: narrow text, no margin notes
% - margin/default: restore default layout
\newcommand{\setlayout}[1]{
  \ifstrequal{#1}{extrawide}
    {\newgeometry{includeall,nomarginpar,top=14mm,bottom=14mm,left=15mm,right=15mm,headheight=16pt}}{
  \ifstrequal{#1}{extranarrow}
    {\newgeometry{includeall,nomarginpar,top=14mm,bottom=14mm,left=35mm,right=35mm,headheight=16pt}}{
  \ifstrequal{#1}{margin}
    {\restoregeometry}{
  \ifstrequal{#1}{default}
    {\restoregeometry}{
  \PackageError{setlayout}{Undefined option to the setlayout command}{
  }}}}}
}

% Ensure auto-inserted blank pages remain blank.
\RequirePackage{emptypage}

% ===================================================================
% 19. HEADERS & FOOTERS (FANCYHDR)
% ===================================================================
\RequirePackage{fancyhdr}
  \pagestyle{fancy}
  \renewcommand{\chaptermark}[1]{\markboth{#1}{}}
  \renewcommand{\sectionmark}[1]{\markright{\thesection\ #1}}
  
  % Header-Footer style for standard (chapter) pages
  \fancypagestyle{fancy-chapter}{
    \fancyhf{}
    \fancyheadoffset[LE,RO]{\marginparsep+\marginparwidth}
    \fancyhead[LE,RO]{\thepage}
    \fancyhead[RE]{\textsl{\leftmark}}
    \fancyhead[LO]{\textsl{\rightmark}}
    \renewcommand{\headrulewidth}{0pt}
  }

  % Header-Footer style showing only page numbers
  \fancypagestyle{fancy-pagenum}{
    \fancyhf{}
      \fancyheadoffset[LE,RO]{\marginparsep+\marginparwidth}
    \fancyhead[RO,LE]{\thepage}
    \renewcommand{\headrulewidth}{0pt}
  }

  % Redefining the 'plain' header-footer style to be empty
  \fancypagestyle{plain}{
    \fancyhf{}
    \renewcommand{\headrulewidth}{0pt} 
  }

% Activating the default header-footer style
\pagestyle{fancy-chapter}
% ===================================================================
% 20. FONTS (PROJECT FONTS + FILE-BASED FONTS)
% ===================================================================
\setmainfont{}[
    Path = ./Fonts/Minion3FontFamily/,
    Ligatures = {TeX, Common},
    Kerning = On,
    Numbers = {Proportional, OldStyle},
    UprightFont = Minion3-Medium,
    BoldFont = Minion3-Bold,
    ItalicFont = Minion3-Italic,
    BoldItalicFont = Minion3-BoldItalic,
    UprightFeatures = {
        SizeFeatures = {
            {Size = {-9.9}, Font=Minion3Caption-Regular},
            {Size = {9.9-13.9}, Font=Minion3-Regular},
            {Size = {13.9-25.9}, Font=Minion3Subhead-Regular},
            {Size = {25.9-}, Font=Minion3Display-Regular}
        }
    },
    BoldFeatures = {
        SizeFeatures = {
            {Size = {-9}, Font=Minion3Caption-Bold},
            {Size = {9-14}, Font=Minion3-Bold},
            {Size = {14-24}, Font=Minion3Subhead-Bold},
            {Size = {24-}, Font=Minion3Display-Bold}
        }
    },
    ItalicFeatures = {
        SizeFeatures = {
            {Size = {-9}, Font=Minion3Caption-Italic},
            {Size = {9-14}, Font=Minion3-Italic},
            {Size = {14-24}, Font=Minion3Subhead-Italic},
            {Size = {24-}, Font=Minion3Display-Italic}
        }
    },
    BoldItalicFeatures = {
        SizeFeatures = {
            {Size = {-9}, Font=Minion3Caption-BoldItalic},
            {Size = {9-14}, Font=Minion3-BoldItalic},
            {Size = {14-24}, Font=Minion3Subhead-BoldItalic},
            {Size = {24-}, Font=Minion3Display-BoldItalic}
        }
    },
    FontFace = {sb}{n}{
        Font = Minion3-Semibold,
        SizeFeatures = {
            {Size = {-9}, Font=Minion3Caption-Semibold},
            {Size = {9-14}, Font=Minion3-Semibold},
            {Size = {14-24}, Font=Minion3Subhead-Semibold},
            {Size = {24-}, Font=Minion3Display-Semibold}
        }
    },
    FontFace = {sb}{it}{
        Font = Minion3-SemiboldItalic, 
        SizeFeatures = {
            {Size = {-9}, Font=Minion3Caption-SemiboldItalic},
            {Size = {9-14}, Font=Minion3-SemiboldItalic},
            {Size = {14-24}, Font=Minion3Subhead-SemiboldItalic},
            {Size = {24-}, Font=Minion3Display-SemiboldItalic}
        }
    },
    FontFace = {mb}{n}{
        Font = Minion3-Medium,
        SizeFeatures = {
            {Size = {-9}, Font=Minion3Caption-Medium},
            {Size = {9-14}, Font=Minion3-Medium},
            {Size = {14-24}, Font=Minion3Subhead-Medium},
            {Size = {24-}, Font=Minion3Display-Medium}
        }
    },
    FontFace = {mb}{it}{
        Font = Minion3-MediumItalic,
        SizeFeatures = {
            {Size = {-9}, Font = Minion3Caption-MediumItalic},
            {Size = {9-14}, Font = Minion3-MediumItalic},
            {Size = {14-24}, Font = Minion3Subhead-MediumItalic},
            {Size = {24-}, Font = Minion3Display-MediumItalic}
        }
    }
]


% \setmainfont{}[
%     Path = ./Fonts/STIXTwo/,
%     Extension = .otf,
%     UprightFont = STIXTwoText-Regular,
%     BoldFont = STIXTwoText-Bold,
%     ItalicFont = STIXTwoText-Italic,
%     BoldItalicFont = STIXTwoText-BoldItalic,
%     FontFace = {md}{n}{Font = STIXTwoText-Medium},
%     FontFace = {md}{it}{Font = STIXTwoText-MediumItalic},
%     FontFace = {sb}{n}{Font = STIXTwoText-SemiBold},
%     FontFace = {sb}{it}{Font = STIXTwoText-SemiBoldItalic},
% ]

\DeclareTextFontCommand{\textmd}{\fontseries{md}\selectfont}
\DeclareTextFontCommand{\textsb}{\fontseries{sb}\selectfont}

\setsansfont{}[
    Path = ./Fonts/MyriadProFontFamily/,
    % Myriad Pro
    UprightFont = MyriadPro-Regular,
    BoldFont = MyriadPro-Bold,
    ItalicFont = MyriadPro-It,
    BoldItalicFont = MyriadPro-BoldIt,
    FontFace = {l}{it}{MyriadPro-LightIt},
    FontFace = {l}{n}{MyriadPro-Light},
    FontFace = {sb}{n}{MyriadPro-Semibold},
    FontFace = {sb}{it}{MyriadPro-SemiboldIt},
    FontFace = {k}{n}{MyriadPro-Black},
    FontFace = {k}{it}{MyriadPro-BlackIt},
    % Myriad Pro Condensed
    FontFace = {lc}{n}{MyriadPro-LightCond},
    FontFace = {lc}{it}{MyriadPro-LightCondIt},
    FontFace = {c}{n}{MyriadPro-Cond},
    FontFace = {c}{it}{MyriadPro-CondIt},
    FontFace = {sbc}{n}{MyriadPro-SemiboldCond},
    FontFace = {sbc}{it}{MyriadPro-SemiboldCondIt},
    % FontFace = {bc}{n}{MyriadPro-Cond},
    % FontFace = {bc}{it}{MyriadPro-CondIt},
    FontFace = {kc}{n}{MyriadPro-BlackCond},
    FontFace = {kc}{it}{MyriadPro-BlackCondIt},
    % Myriad Pro SemiCondensed
    FontFace = {lsc}{n}{MyriadPro-LightSemiCn},
    FontFace = {lsc}{it}{MyriadPro-LightSemiCn},
    FontFace = {sc}{n}{MyriadPro-SemiCn},
    FontFace = {sc}{it}{MyriadPro-SemiCnIt},
    FontFace = {sbsc}{n}{MyriadPro-SemiboldSemiCn},
    FontFace = {sbsc}{it}{MyriadPro-SemiboldSemiCnIt},
    FontFace = {bsc}{n}{MyriadPro-BoldSemiCn},
    FontFace = {bsc}{it}{MyriadPro-BoldSemiCnIt},
    FontFace = {ksc}{n}{MyriadPro-BlackSemiCn},
    FontFace = {ksc}{it}{MyriadPro-BlackSemiCnIt},
    % Myriad Pro SemiExtended
    FontFace = {lsx}{n}{MyriadPro-LightSemiExt},
    FontFace = {lsx}{it}{MyriadPro-LightSemiExtIt},
    FontFace = {sx}{n}{MyriadPro-SemiExt},
    FontFace = {sx}{it}{MyriadPro-SemiExtIt},
    FontFace = {sbsx}{n}{MyriadPro-SemiboldSemiExt},
    FontFace = {sbsx}{it}{MyriadPro-SemiboldSemiExtIt},
    FontFace = {bsx}{n}{MyriadPro-BoldSemiExt},
    FontFace = {bsx}{it}{MyriadPro-BoldSemiExtIt},
    FontFace = {ksx}{n}{MyriadPro-BlackSemiExt},
    FontFace = {ksx}{itab}{MyriadPro-BlackSemiExtIt},
]

% \setsansfont{}[
%     Path = ./Fonts/NotoSans/, 
%     Extension = .ttf,
%     UprightFont = NotoSans-Regular,
%     BoldFont = NotoSans-Bold,
%     ItalicFont = NotoSans-Italic,
%     FontFace = {c}{n}{Font = NotoSans_Condensed-Regular},
%     FontFace = {c}{it}{Font = NotoSans_Condensed-Italic},
%     FontFace = {sbc}{n}{Font = NotoSans_Condensed-SemiBold},
%     FontFace = {sbc}{it}{Font = NotoSans_Condensed-SemiBoldItalic},
% ]

\DeclareTextFontCommand{\textc}{\fontseries{c}\selectfont}
\DeclareTextFontCommand{\textsbc}{\fontseries{sbc}\selectfont}

\setmonofont{}[
    Path = ./Fonts/JetBrainsMonoNL/,
    Extension = .ttf,
    UprightFont = JetBrainsMonoNL-Regular,
    BoldFont = JetBrainsMonoNL-Bold,
    ItalicFont = JetBrainsMonoNL-Italic,
    BoldItalicFont = JetBrainsMonoNL-BoldItalic,
    Scale=MatchLowercase
]

\setmathfont{STIXTwoMath-Regular}[
    Path = ./Fonts/STIXTwo/,
    Extension = .otf,
]

% ===================================================================
% 21. CODE LISTINGS (C++ STYLE)
% ===================================================================


\NewTCBInputListing[auto counter,number within=section]{\code}{O{} m m +!O{}}{%  
    listing engine=minted,
    minted style=xcode,
    minted language={#3},
    minted options={fontsize=\small,breaklines,autogobble,linenos,numbersep=4mm},
    listing file={#2},
    enhanced,
    title={\makebox[1.2em] {\faFileCode[regular]} Listing \thetcbcounter \hfill \textit{#4} \hfill \phantom{\makebox[1.2em]{\faEdit} Remark \thetcbcounter}},
    boxrule=0pt,
    toptitle=2pt, bottomtitle=2pt, lefttitle=5pt, righttitle=5pt,
    left=15pt, right=5pt, top=5pt, bottom=5pt,
    % colframe=tailwindalmond100,
    coltitle=tailwindplatinum800,
    colback=tailwindplatinum50,
    colbacktitle=tailwindplatinum100,
    fonttitle=\sffamily\fontseries{sc}\small,
    listing only,
    #1}

\NewTCBListing[auto counter,number within=section]{xcode}{O{} m +!O{}}{%  
    listing engine=minted,
    minted style=xcode,
    minted language={#2},
    minted options={fontsize=\small,breaklines,autogobble,linenos,numbersep=4mm},
    enhanced,
    title={\makebox[1.2em] {\faFileCode[regular]} Listing \thetcbcounter \hfill \textit{#3} \hfill \phantom{\makebox[1.2em]{\faEdit} Remark \thetcbcounter}},
    boxrule=0pt,
    toptitle=2pt, bottomtitle=2pt, lefttitle=5pt, righttitle=5pt,
    left=15pt, right=5pt, top=5pt, bottom=5pt,
    % colframe=tailwindalmond100,
    coltitle=tailwindplatinum800,
    colback=tailwindplatinum50,
    colbacktitle=tailwindplatinum100,
    fonttitle=\sffamily\fontseries{sc}\small,
    listing only,
    #1}

% \NewTCBInputListing{\icode}{m m}{
%   {\mintinline{#1}{#2}}
% }

% 1. Define the visual style of the inline box
% \newtcbox{\icodestyle}[1][tailwindplatinum600]{%
%     on line, % Crucial for inline text
%     arc=2pt,
%     colback=#1!5!white,
%     colframe=#1!75!black,
%     boxrule=0.5pt,
%     boxsep=0pt,
%     left=2pt, right=2pt, top=1pt, bottom=1pt,
%     fontupper=\small\ttfamily
% }

% 2. Create the \icode command
% #1 = language (e.g., powershell), #2 = code
\NewDocumentCommand{\icode}{m m}{%
    \mintinline{#1}{#2}}%

% \RequirePackage{listings}

% \lstdefinestyle{c++}{
%     language=C++,                       
%     backgroundcolor=\color{white!97!iRedOnLight},     
%     basicstyle=\ttfamily\scriptsize,         
%     identifierstyle=\color{iIndigoOnLight},
%     keywordstyle=\color{iRedOnLight}, 
%     stringstyle=\color{iMintOnLight},        
%     commentstyle=\color{iGrayOnLight}\itshape, 
%     numberstyle=\tiny\color{iGrayOnLight},      
%     directivestyle=\color{iYellowOnLight},
%     % rulecolor=\color{white!75!iRedOnLight},
%     rulecolor=\color{white!97!iRedOnLight},
%     % Đây là phần set cho number
%     numbers=left,                       % Line numbers on the left
%     stepnumber=1,                       % Line number increment
%     numbersep=10pt,                      % Space between code and line numbers
%     frameround=tttt,
%     numberblanklines=true,
%     firstnumber=auto,
%     tabsize=4,                          % Tab size (spaces per tab)
%     showstringspaces=false,             % Don't show spaces in strings
%     breaklines=true,                    % Line breaking
%     breakatwhitespace=true,             % Break only at whitespace
%     frame=single,                       % Frame around the code block
%     captionpos=b,                       % Caption below the code block
%     escapeinside={(*@}{@*)},            % Escape to LaTeX with (*@ ... @*)
%     showspaces=false,               
%     showtabs=false, 
%     morekeywords={alignas, alignof, and, and_eq, asm, atomic_cancel, atomic_commit, atomic_noexcept, auto, bitand, bitor, bool, break, case, catch, char, char8_t, char16_t, char32_t, class, compl, concept, const, consteval, constexpr,constinit, const_cast, continue, co_await, co_return, co_yield, decltype, default, delete, do, double, dynamic_cast, else, enum, explicit, export, extern, false, float, for, friend, goto, if, inline, int, long, mutable, namespace, new, noexcept, not, not_eq, nullptr, operator,or, or_eq, private, protected, public, reflexpr, register, reinterpret_cast, requires, return, short, signed,sizeof, static, static_assert, static_cast, struct, switch, synchronized, template, this, thread_local, throw, true, try, typedef, typeid, typename, union,unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq, final, override}, 
% }

% \lstset{style=c++}

% ===================================================================
% 22. HYPERLINKS + PDF BOOKMARKS (LOAD LATE)
% ===================================================================
\RequirePackage{hyperref}
\hypersetup{
  colorlinks=true,
  % hidelinks,
  linktoc=all,
  citecolor=crimson,
  linkcolor=tailwindvermillion600,
  filecolor=teal,
  urlcolor=teal,
  bookmarksnumbered=true,
  pdfpagemode=UseOutlines
}
\RequirePackage{bookmark}

% ===================================================================
% 23. DEBUGGING / DEVELOPMENT (DISABLE FOR RELEASE)
% ===================================================================
%\RequirePackage{showframe}
