#include "GameController.h"
#include "BoardBuilder.h"


GameController::GameController() {
    BoardBuilder builder;
    board = builder.build();
}


