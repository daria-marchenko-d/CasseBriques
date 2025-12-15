# CasseBriques
## Project description
### English Version
#### Main Elements:
* Platform/cannon moving at the bottom of the screen.
* Ball that bounces off walls, platform, and bricks.
* Bricks with varying health points that change color when damaged and are destroyed.
* Shooting mechanics: left-click shoots in the aimed direction, right-click triggers a shockwave.
* Collision handling system, including angular and advanced collisions.
#### Bonus Features:
* Support for multiple simultaneous balls.
* Level loading from external files.
* Resource management via an AssetManager.

##### To successfully develop the project, the following are required:
Define classes: GameObject (base), Ball, Paddle(Canon), Brick, Game (manager).
Implement the main game loop handling SFML events (keyboard and mouse).
Handle collisions: ball with walls, ball with paddle, ball with bricks (AABB for bricks, circle for ball).
Visualization of different bricks.
Resource management: loading textures, sounds using the AssetManager.
Shooting logic: one ball/shockwave at a time; limit simultaneous balls.
Level state storage (e.g., reading from a text file).
#### Elements to create:
##### Classes:
GameObject (common properties: position, size, collisions)
Ball (movement logic, bouncing)
Paddle/Canon (movement, rotation following mouse)
Brick (health, color change, destruction)
InputManager (keyboard, mouse input handling)
AssetManager (resource management)
LevelManager (level loading)
##### Main game loop: update, render, event processing.
Collision system (for ball, paddle, bricks, shockwave).
UI/graphics displaying brick health and score.
project implementation plan

#### Work Phases 
Phase 1: Preparation and Basic Architecture (1-1.5 days)

Setting up development environment.
Creating UML diagrams.
Initializing main game loop.
Implementing base classes (GameObject, InputManager).

Phase 2: Core Game Mechanics (1.5-2 days)

Implementation of cannon, ball, bricks.
Introduction of shooting and shockwave.
Development of descending wall — key challenge element.
Handling collisions.
Gameplay tuning.

Phase 3: Extension and Optimization (1-2 days)

Implementation of resource and level managers.
Multi-ball support.
Adding UI.
Code optimization and refactoring.

Phase 4: Testing and Finalization (0.5-1 day)

Comprehensive mechanics testing.
Bug fixing.
Project documentation.


#### Basic Development
Stage 1: Environment and Project Setup

Install SFML and configure the IDE for development.
Create directory structure separating header files and source files.
Develop UML diagrams for main classes (GameObject, Canon, Ball, Brick, InputManager).
Initialize the SFML window and launch the main game loop.

Stage 2: Implementation of Base Classes and Movement Mechanics

GameObject: implement fields for position, size, and collision area.
InputManager: listen and handle keyboard and mouse events.
Implement rendering of basic primitives (circle for the ball, rectangles for the cannon and bricks).
Logic for the cannon to follow the mouse cursor.
Ball movement and bouncing off walls, platform, and bricks.

Stage 3: Implementation of Game Mechanics and Collisions

Create Brick class with health, color change on damage, and deletion after destruction.
Implement collision detection between ball and bricks/platform.
Logic for reducing bricks' health and updating their visual state.

Stage 4: Shooting and Shockwave Mechanic

User interaction: left click launches ball from the cannon.
Handle restriction of only one active ball at a time.
Right click initiates shockwave that pushes balls away.
Account for shockwave effects on other objects.

Stage 5: Implementation of Descending Wall

Create an object representing the wall descending slowly from the top down.
Loss condition if wall reaches platform area.
Adjust wall movement speed depending on game state.
Integrate with main game loop.

Stage 6: Testing Basic Mechanics

Thorough testing of movements, collisions, shooting, and descending wall dynamics.
Identification and bug fixing.

#### Additional Tasks
AssetManager: implement resource manager for loading and caching textures and sounds.
LevelManager: create level manager that reads configurations from files and generates game field.
Multi-ball Support: add logic for simultaneous operation of multiple balls including their movements and collisions.
UI: develop user interface displaying bricks' health and current score.
Optimization and Refactoring: improve code architecture and quality, remove duplications.
Final Testing and Documentation: comprehensive project testing and technical documentation preparation.




### French Version
#### Éléments principaux :
- Plateforme/canon se déplaçant en bas de l'écran.
- Balle qui rebondit sur les murs, la plateforme et les briques.
- Briques avec plusieurs points de vie qui changent de couleur lorsqu'elles sont endommagées et qui sont détruites.
- Mécaniques de tir : clic gauche pour tirer dans la direction visée, clic droit pour déclencher une onde de choc.
- Système de gestion des collisions, incluant les collisions angulaires et complexes.
#### Fonctionnalités bonus :
- Support de plusieurs balles simultanées.
- Chargement des niveaux depuis des fichiers.
- Gestion des ressources via un AssetManager.

##### Pour réussir le développement, il faut :
Définir les classes : GameObject (de base), Ball, Paddle(Canon), Brick, Game (gestionnaire).
Implémenter la boucle principale du jeu avec gestion des événements SFML (clavier et souris).
Gérer les collisions : balle avec murs, balle avec la plateforme, balle avec les briques (AABB pour les briques, cercle pour la balle).
Visualisation des différents types de briques et changement de couleur.
Gestion des ressources : chargement des textures, sons via l'AssetManager.
Logique de tir : une balle/onde de choc à la fois, limitation des balles simultanées.
Stockage de l'état des niveaux (ex : lecture depuis un fichier texte).

#### Éléments à développer :
##### Classes :
GameObject (propriétés générales : position, taille, collisions)
Ball (logique de mouvement, rebond)
Paddle/Canon (contrôle, rotation suivant la souris)
Brick (points de vie, changement de couleur, destruction)
InputManager (gestion des entrées clavier et souris)
AssetManager (gestion des ressources)
LevelManager (chargement des niveaux)
##### Boucle principale du jeu : mise à jour, rendu, gestion des événements.
Système de collisions (pour la balle, la plateforme, les briques, l’onde de choc).
Interface graphique affichant les points de vie des briques et le score.


#### Phases de travail
Phase 1 : Préparation et architecture de base (1-1,5 jour)

Installation de l'environnement de développement.
Création des diagrammes UML.
Initialisation de la boucle principale de jeu.
Implémentation des classes de base (GameObject, InputManager).

Phase 2 : Mécaniques principales de jeu (1,5-2 jours)

Implémentation du canon, de la balle et des briques.
Mise en place du tir et de l'onde de choc.
Développement du mur descendant, élément clé de difficulté.
Gestion des collisions et ajustements du gameplay.

Phase 3 : Extension et optimisation (1-2 jours)

Mise en place des gestionnaires de ressources et de niveaux.
Support multi-balles.
Amélioration de l’UI.
Optimisation et refactoring du code.

Phase 4 : Test et finalisation (0,5-1 jour)

Tests approfondis.
Correction des bugs.
Documentation du projet.

#### Développement de base

Étape 1 : Préparation de l'environnement et du projet

Installer SFML et configurer l'IDE pour le développement.
Créer une structure de répertoires distincts pour les fichiers d'en-tête et les fichiers source.
Concevoir les diagrammes UML pour les classes principales (GameObject, Canon, Ball, Brick, InputManager).
Initialiser la fenêtre SFML et lancer la boucle principale du jeu.

Étape 2 : Mise en œuvre des classes de base et des mécaniques de mouvement

GameObject : implémenter les champs pour la position, la taille et la zone de collision.
InputManager : écouter et gérer les événements clavier et souris.
Implémenter le rendu des formes primitives de base (cercle pour la balle, rectangles pour le canon et les briques).
Logique pour que le canon suive le curseur de la souris.
Mouvement de la balle et rebond sur les murs, la plateforme et les briques.

Étape 3 : Implémentation des mécaniques de jeu et des collisions

Créer la classe Brick avec la gestion des points de vie, changement de couleur selon les dégâts, suppression après destruction.
Vérifier les collisions entre la balle et les briques ainsi que la plateforme.
Logique de réduction de la « vie » des briques et mise à jour de leur état visuel.

Étape 4 : Mécanique de tir et onde de choc

Interaction utilisateur : clic gauche pour tirer la balle à partir du canon.
Gérer la limite d'une seule balle active à la fois.
Clic droit pour déclencher l'onde de choc qui repousse les balles.
Prendre en compte l'effet de l'onde de choc sur les autres objets.

Étape 5 : Implémentation du mur descendant

Créer un objet visuel pour le mur descendant qui se déplace lentement du haut vers le bas.
Condition de défaite si le mur atteint la zone proche de la plateforme.
Régler la vitesse du mur selon l'état du jeu.
Intégration avec la boucle principale de jeu.

Étape 6 : Tests des mécaniques de base

Tester en profondeur les mouvements, collisions, tirs et dynamique du mur descendant.
Identifier et corriger les bugs.

#### Tâches supplémentaires
AssetManager : implémenter la gestion des ressources pour le chargement et la mise en cache des textures et sons.
LevelManager : créer un gestionnaire de niveaux lisant les configurations de fichiers et générant le terrain de jeu.
Support de plusieurs balles : ajouter la logique pour gérer simultanément plusieurs balles et leurs collisions.
UI : développer une interface utilisateur affichant la vie des briques et le score actuel.
Optimisation et refactoring : améliorer l’architecture et la qualité du code, éliminer les redondances.
Tests finaux et documentation : réaliser des tests complets du projet et rédiger la documentation technique.

## Files tree

/project_root
│
├── /include                     # Header files (.hpp)
│   ├── GameObject.hpp          # Base class declarations (position, size, collision zone)
│   ├── Canon.hpp               # Cannon class declaration (aiming, shooting)
│   ├── Ball.hpp                # Ball class declaration (movement, collisions)
│   ├── Brick.hpp               # Brick class declaration (health, visuals)
│   ├── InputManager.hpp        # Input handling (keyboard/mouse events)
│   ├── AssetManager.hpp        # Resource manager singleton (textures, sounds)
│   ├── LevelManager.hpp        # Level loading and management
│   ├── Collision.hpp           # Collision detection functions (circle vs AABB)
│   └── HUD.hpp                 # Optional UI elements (score, lives display)
│
├── /src                        # Source files (.cpp)
│   ├── GameObject.cpp          # Base class implementations
│   ├── Canon.cpp               # Cannon logic
│   ├── Ball.cpp                # Ball behavior implementation
│   ├── Brick.cpp               # Brick damage and rendering
│   ├── InputManager.cpp        # Keyboard and mouse input processing
│   ├── AssetManager.cpp        # Resource loading and caching
│   ├── LevelManager.cpp        # Parsing and spawning levels
│   ├── Collision.cpp           # Collision checks implementation
│   └── HUD.cpp                 # UI rendering
│
├── main.cpp                    # Application entry point, main game loop
│
├── /assets                     # Game assets: sprites, fonts, sounds
│   ├── textures/
│   ├── fonts/
│   └── sounds/
│
├── /levels                     # Level data files (text, JSON)
│   └── level1.txt
│
├── README.md                   # Project overview and build instructions
├── CMakeLists.txt or Makefile # Build system configuration

