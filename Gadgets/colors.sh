!#/bin/bash
colors() {
        local fgc bgc vals seq0

        printf "Color escapes are %s\n" '\e[${value};...;${value}m'
        printf "Values 30..37 are \e[36mforeground colors\e[m\n"
        printf "Values 40..47 are \e[46mbackground colors\e[m\n"
        printf "Value  1 gives a  \e[1mbold-faced look\e[m\n"
        printf "Value  3 gives a  \e[3mitalic look\e[m\n"
        printf "Value  4 gives a  \e[4munderline\e[m\n"
        printf "Value  5 gives a  \e[5mflashing effect to the text\e[m\n"
        printf "Value  7 gives an \e[7mhighlight\e[m\n\n"
}
