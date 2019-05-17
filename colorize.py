# -*- coding: utf-8 -*-
# Используем Pygments, чтобы раскрасить код
from pygments.lexers import CLexer
from pygments.formatters import HtmlFormatter
from pygments import highlight
from os import listdir,getcwd

formatter = HtmlFormatter(full=True, style='tango')
lex = CLexer()

for file in listdir(getcwd()):
    if file.endswith(".c") or file.endswith(".h"):
        with open(file+".html", "w") as outf:
            with open(file,"r") as inputf:
                outf.write(highlight(inputf.read(), lex, formatter).replace("charset=None","charset=UTF-8"))
