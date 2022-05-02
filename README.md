# Introduction
Obiwan est un pointeur laser capable de s’orienter dans n’importe quelle direction.  


https://user-images.githubusercontent.com/80780126/166306557-4985dba1-e16e-4158-aaa8-b6b7efb4e9a4.mp4


## Contexte
Nous sommes le club d'informatique du lycée Camille Claudel avec environ 8 membres actifs. Étant un club très jeune et géré exclusivement par des élèves, nous sommes fiers de vous présenter ce projet, fait en quelques semaines avec un budget très réduit. Nous espérons que vous apprécierez lire cette présentation autant que nous avons apprécié réaliser ce projet !

## Objectifs
L’objectif principal est de pouvoir orienter le laser dans une direction arbitraire.  
Nous espérons ensuite pouvoir utiliser le dispositif pour dessiner un motif et le capturer à l’aide d’une photo à pose longue, à la manière du [light painting](https://fr.wikipedia.org/wiki/Light_painting).  
Enfin, si tous les objectifs précédents sont remplis, nous essayerons d’automatiser le contrôle du laser pour dessiner un motif à partir d’une image vectorielle.


# Principe de fonctionnement
Pour diriger le laser, nous utiliserons deux moteurs: l’un qui contrôle le mouvement gauche-droite, appelé azimut, et l’autre qui contrôle l'axe haut-bas, appelé altitude. Ce vocabulaire est emprunté au système de coordonnées céleste appelé “[système de coordonnées horizontales](https://fr.wikipedia.org/wiki/Syst%C3%A8me_de_coordonn%C3%A9es_horizontales)”, utilisé en astronomie:  
<img src="https://user-images.githubusercontent.com/80780126/166306821-bf280f1e-2414-4a3a-b8d1-f09e87380460.png" width=600/>  
Pour photographier les motifs créés, nous utiliserons la technique du light painting. Elle consiste à prendre une photo avec un temps de pose (la durée pendant laquelle l’appareil photo capte de la lumière) relativement long, pour faire apparaître sur l’image la trajectoire du point lumineux.

# Problèmes rencontrés et solutions apportées

## Choix de fabrication/architecture
Le mouvement est contrôlé par des servomoteurs et une carte Arduino. Le moteur azimut entraîne une roue d’engrenage sur laquelle est positionné le moteur altitude. Le laser est scotché sur le moteur altitude. La structure est imprimée en 3D en PLA.  
![image](https://user-images.githubusercontent.com/80780126/166307062-0f8a52ee-c8aa-43f6-8f16-d6c89f8f876d.png)
![image](https://user-images.githubusercontent.com/80780126/166307099-b4255e1a-fe26-491c-82f4-a447b0046917.png)  
Le moteur altitude est positionné au centre le son engrenage, ce qui fait que le laser a une excentricité par rapport à l’axe azimutal. La droite du rayon du laser n’est donc pas sécante avec l’axe de rotation azimutal.

## Excentricité
Cette excentricité conduit les dessins à être déformés. Pour y remédier, le programme prend en entrée les coordonnées du point visé, et calcule l’angle à donner aux moteurs pour le pointer malgré l’excentricité.  
![image](https://user-images.githubusercontent.com/80780126/166308689-368ebcb9-e887-4404-9652-a118af46dde1.png)
![image](https://user-images.githubusercontent.com/80780126/166318085-f74e0ee7-72b7-46fe-b2c1-376ae7fb0652.png)

## Précision
Au départ, nous dessinions sur un mur à environ 1.5m du laser. Le tracé manquait cependant de précision, car nos moteurs ont une précision de seulement environ 1 degré. Nous avons donc d’abord réduit la taille de l’engrenage de l’axe azimutal pour avoir une réduction 1:2, et ainsi avoir une précision de 0.5 degré. Cela a eu pour effet secondaire de rendre le dispositif plus compact.  
![image](https://user-images.githubusercontent.com/80780126/166307678-a5ea725c-1b01-4755-bfef-e8f0f0508044.png)
![image](https://user-images.githubusercontent.com/80780126/166307695-3df06654-ef28-47ff-a666-2f97a2c44818.png)  
Cela n’a pas suffi à régler le problème, car la précision de l’axe altitude est restée la même, et même ces 0.5 degrés de précisions n’étaient pas suffisants. Nous avons alors réalisé que simplement rapprocher le dispositif de la surface de dessin augmentait grandement la précision, car les dessins faisaient alors plus de degrés de large.

## Rectilinéarité
![image](https://user-images.githubusercontent.com/80780126/166308366-e91a8e04-d8c8-4f3f-92f0-0270a33bceea.png)
Avec notre dispositif, nous pouvions pointer une position donnée, mais lors du déplacement d’une position à une autre le tracé n’était pas droit, car la vitesse des moteurs n’est pas constante. Pour tracer des segments, on pointe donc vers des positions intermédiaires.
![image](https://user-images.githubusercontent.com/80780126/166308571-aa56e814-be3c-4011-aa1e-eaa3a127aa91.png)
En ajoutant plus de points intermédiaires, les traits sont plus rectilignes et plus uniformes.
![image](https://user-images.githubusercontent.com/80780126/166308623-a9f9e04d-d702-4515-877b-3ea1268c0509.png)

# Résultat final
<img src="https://user-images.githubusercontent.com/80780126/166318702-3d864c41-caeb-41f9-8542-3f91ea5c6d73.jpg" width=500/> <img src="https://user-images.githubusercontent.com/80780126/166318712-b028cbc9-84d0-4c5f-a94d-be613f9db314.jpg" width=500/>
