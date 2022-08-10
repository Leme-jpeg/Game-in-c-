# Game-in-c-
C++ game

Comment jouer ?
Le jeu est composé d'un damier de 8 lignes et 12 colonnes. L'objectif « ultime » est, en se 
déplaçant sur le damier, de découvrir 15 cases où il y a des $$$$ cachés, et bien sûr de 
ramasser ces $$$$. Le jeu se termine lorsqu'on a cumulé 15 points (ou si on ferme la fenêtre 
du jeu). Tout déplacement illégal sera signalé par un beep (tentative de déplacement hors du 
jeu ou sur une case de type mur en noir).
Chaque case du jeu est visible sous une des formes suivantes:
• pierre blanche
• pierre grise
• mur en noir
• $$$$
Au début toutes les cases forment un mur en noir ou sont composées de pierre blanche. 
Lorsque vous quitterez une case pierre blanche, celle-ci deviendra pierre grise ou bien $$$$ (si 
c'est votre jour de chance).
Si vous avez découvert une case $$$$, retournez-y pour amasser votre fortune. En quittant la 
case $$$$ celle-ci devient pierre grise.
Lorsque vous quitterez une case pierre grise elle deviendra mur en noir, et vous ne pourrez 
plus passer par-là
