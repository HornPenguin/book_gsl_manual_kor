
packagelist= {
    "xeCJK" : "CJKspace",
    "afterpage" : "",
    "pagecolor" : "pagecolor=none",
    "tikz" : "",
    "tikzpagenodes" : "",
    "fix-cm" : "",
    "textpos" : "absolute, overlay",
}

packages = "\n".join(["\\usepackage[{}]{{{}}}".format(v, k) for k, v in packagelist.items()])

custom_setting = r'''

    \definecolor{coverbackground}{RGB}{209, 198, 161} 
    \definecolor{coverband}{RGB}{239, 190, 84}
    '''

cover_page = r'''
    \pagecolor{coverbackground}\afterpage{\nopagecolor}
    
    \begin{tikzpicture}[remember picture,overlay,shift={(current page.north west)}]
        \fill[coverband,yshift=-120mm] rectangle(\paperwidth,85mm);
    \end{tikzpicture}

    \vspace{-0.5cm}\hspace{2.5cm}\includesvg[width=0.6\textwidth]{A_Slick_GNU_Logo.png}

    \begin{textblock\*}{4.25cm}(15cm,5.4cm) % {block width} (coords) 
            \raggedright{
            \Huge\textbf{과학계산}\\
            \Huge\textbf{라이브러리}
            }\\
            \raggedleft\Large\textbf{v2.7}
        \end{textblock\*}

        \begin{textblock\*}{10cm}(9.1cm,9.3cm)
            \raggedleft
            \fontsize{32}{60}\selectfont \textbf{사용 설명서}
    \end{textblock\*}

    \begin{center}
        \vfill
        \large \textbf{Mark Galassi \\ et al} \\
        \vspace{2cm}
        \Large \textbf{GNU Publication}
    \end{center}
'''

license_page = r'''
    \includegraphics[width=0.4\textwidth]{gfdl_logo.png}

    이 사용 설명서는 GNU 자유 문서 사용 허가서(GDFL)를 따릅니다. 
    
    Copyright (c)  2022  김현성.
    Permission is granted to copy, distribute and/or modify this document under 
    the terms of the GNU Free Documentation License, Version 1.3 or any later 
    version published by the Free Software Foundation; with no 
    Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts. 
    A copy of the license is included in the section entitled 
    "GNU Free Documentation License".

    \includegraphics[width=0.4\textwidth]{gpl_v3_logo.png}

    이 사용 설명서 내의 모든 예제와 소스 코드들은 GNU 일반 공중 사용 허가서(GPL)를 따릅니다.

    표지 디자인과 GPL, GDFL 로고들은 모두 GPL을 따릅니다.
    

    \begin{textblock\*}{25cm}(3cm,22cm)
    \underline{\textbf{판본 정보}}\\~\\
    \small{
        제목: \booktitle\\
        저자: \bookauthor\\
        번역: \booktranslator\\
        출판사: GNU Publication\\
        출판 년도: 2022\\
        ISBN: -----------------\\
        DOI: -----------------
        }
    \end{textblock\*}
    '''