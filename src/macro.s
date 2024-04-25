    .macro b_logic label
blt cr6, \label
    .endm

    .macro laddr reg label
lis \reg, \label@ha
ori \reg, \reg, \label@l
    .endm
