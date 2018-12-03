# -*- coding: utf-8 -*-
from pygments.lexers import JsonLexer
from pygments.formatters import HtmlFormatter
from pygments import highlight
from os import listdir,getcwd

formatter = HtmlFormatter(full=True, style='tango')
lex = JsonLexer()

file = "Data.json"
with open(file+".html", "w") as outf:
    with open(file,"r") as inputf:
        outf.write(highlight(inputf.read(), lex, formatter).replace("charset=None","charset=UTF-8"))
