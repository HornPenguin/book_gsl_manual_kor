
packagelist= {
    "pdfpages" :"",
    "xeCJK" : "CJKspace",
    "multicol":"",
    "setspace":"",
    "imakeidx": ""
}

#    "xeCJK" : "CJKspace",

packages = "\n".join(["\\usepackage[{}]{{{}}}".format(v, k) for k, v in packagelist.items()])

custom_setting = r'''
%setspace 패키지 설정: CJK가 주인 문서에서 줄간격이 너무 좁을 때
\onehalfspacing
%\setstretch{1.25} % custom spacing
%------------------------------------------------------------

%%\setsansfont{NanumBarunGothic}[
%%    Mapping=tex-text, 
%%    Path=./,
%%    Extension = .ttf
%%    ]
%%\setmainfont{Nanum Myeongjo}[
%%    Mapping=tex-text, 
%%    Path=./,
%%    Extension = .ttf
%%    ]
%%
'''

fontpkg= r'''
%\setmainfont{Noto Serif CJK KR}
%\setsansfont{Noto Sans CJK KR}
%\setmonofont{Noto Sans Mono CJK KR}

\setmainfont{NanumMyeongjo}[
    Kerning=On,
    Mapping=tex-text
    Path=./,
    Extension = .otf,
    ItalicFont=*Italic,
    BoldFont=*ExtraBold,
    BoldItalicFont=*ExtraBoldItalic
]
\setsansfont{NanumBarunGothic}[
    Path=./,
    Extension = .otf,
    ItalicFont=*Italic,
    BoldFont=*Bold,
    BoldItalicFont=*BoldItalic
]
\setmonofont{D2Coding}[
    Path=./,
    Extension = .ttc
]

\newfontfamily\hangulfont[Script=Hangul]{NanumMyeongjo}
\newfontfamily\hangulfontsf[Script=Hangul]{NanumBarunGothic}
\newfontfamily\hangulfonttt[Script=Hangul]{D2Coding}


'''

maketitle=r'''
\newpage
    \includepdf[pages=-]{Cover.pdf}
\newpage
\sphinxmaketitle
'''
# Void Resources============================================================================
# 15, 5.4
# 9.1, 9.3
license_page = r'''
    \newpage
    \clearpage

    \textbf{원 영문 원서의 저작권 Copyright of the Original English Version:}\\

    \noindent\textbf{Copyright ©} 1996-2021 The GSL Team.\\
    Permission is granted to copy, distribute and/or modify this document under the terms of the
    GNU Free Documentation License, Version 1.3 or any later version published by the Free Software
    Foundation; with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts. 
    A copy of the license is included in the section entitled “GNU Free Documentation License”

    \textbf{번역서의 저작권 Copyright of the Translated Korean Version:}\\
    \noindent\textbf{Copyright ©}  2022  Hyung Seong, Kim. \\
    Permission is granted to copy, distribute and/or modify this document under 
    the terms of the GNU Free Documentation License, Version 1.3 or any later
    version published by the Free Software Foundation; with no  
    Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts. 
    A copy of the license is included in the section entitled 
    "GNU 자유 문서 사용 허가서". Note: in which a surname preceds a given name. \\~\\
    
    \noindent\textbf{Copyright ©}  2022  김현성. \\
    GNU 자유 문서 사용 허가서 1.3판과 자유 소프트웨어 재단에서 발행한 이후의 갱신본의
    규정에 따라, 본 저작물의 복제, 베포 및 수정을 허가합니다. 변경 불가 부분, 앞 표지 구절과
    뒷 표지 구절은 없습니다. 이 허가서의 복사본은 "GNU 자유 문서 사용 허가서"로 지어진 단락에
    포함되어 있습니다.
    
    '''

r'''
\newpage
\pagecolor{coverbackground}
\begin{tikzpicture}[remember picture,overlay,shift={(current page.north west)}]
    \fill[coverband,yshift=-120mm] rectangle(\paperwidth,85mm);
\end{tikzpicture}

\vspace{3.65cm}\hspace{6.8cm}\includegraphics[height=2.85cm]{A_Slick_GNU_Logo.png}

\begin{textblock*}{4.25cm}(15cm,5.4cm) % {block width} (coords) 
        \raggedright{
        \Huge\textbf{과학계산}\\
        \Huge\textbf{라이브러리}
        }\\
        \raggedleft\Large\textbf{v2.7}
    \end{textblock*}

    \begin{textblock*}{10cm}(9.1cm,9.3cm)
        \raggedleft
        \fontsize{32}{60}\selectfont \textbf{사용 설명서}
\end{textblock*}

\begin{center}
    \vfill
    \large \textbf{Mark Galassi \\ et al} \\
    \vspace{0.5cm}
    역: 김현성 \\
    \vspace{1.2cm}
    \Large \textbf{GNU Publication}
    \vspace{3cm}
\end{center}
'''