#pragma once
TTT_W game;
char ft = inputChar("put y or n ",'y','n');
game.setFTurn(ft);
game.whatever = 'e';
game.GameTTT(game.whatever);
return 0;
