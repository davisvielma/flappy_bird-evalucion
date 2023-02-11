# Modificaciones del juego Flappy Bird

## Bird

Se utilizo el patrón estrategia implementar diferentes versiones del personaje de juego, en este caso uno para el mundo normal y el otro para el mundo hard. Este ultimo el personaje se puede mover hacia los lados, traspasa los troncos al adquirir su poder.

## World

Al igual que con el personaje para el mundo se implemento el patrón estrategia para tener dos modos de juego uno normal y el otro hard. Este ultimo hace que algunos troncos se muevan de arriba hacia abajo y también luego de un cierto tiempo habilita el modo de súper poder si el personaje lo logra adquirir.

## PauseState

Estado de juego el cual hace que este se coloque en pausa.

## QuestionState

Estado de juego que pregunta si seguir jugando el modo de juego actual o regresar al menú de inicio.

## TitleScreenState

Se implementaron nuevos atributos a este estado que manejaran los cambios de estado del personaje y el mundo. Los cambios mas grandes están en su método handle_inputs.

## PlayingState

Posee nuevos atributos, se hicieron cambios considerables en sus 4 métodos públicos.

## Seeds

Nueva clase que manipula todo lo correspondiente con el poder del personaje en el modo hard.

## Log

Su método update se renombro como update_x, se le agrego dos nuevos métodos update_y y position_reset_y.

## LogPair

Se agrego un nuevo atributo "move" y dos métodos que ayudaran a la manipulación del par de troncos en el modo hard.

## Game

Se agregaron los nuevos estados de juego al constructor de game.

