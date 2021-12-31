
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

    \vspace{-0.5cm}\hspace{2.5cm}\includegraphics[width=0.6\textwidth]{A_Slick_GNU_Logo.png}

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
    \end{center}
'''
# 15, 5.4
# 9.1, 9.3
license_page = r'''
    \noindent\textbf{Copyright (c)}  2022  김현성. \\
    Permission is granted to copy, distribute and/or modify this document under 
    the terms of the GNU Free Documentation License, Version 1.3 or any later
    version published by the Free Software Foundation; with no  
    Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts. 
    A copy of the license is included in the section entitled 
    "GNU Free Documentation License". 
    '''