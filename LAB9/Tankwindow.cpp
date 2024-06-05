#include "Tankwindow.h"

Tankwindow::Tankwindow()
{
	loadAssets();
}

void Tankwindow::update()
{
}

void Tankwindow::loadAssets()
{
    if (!P1L_texture.loadFromFile("left.png") ||
        !P1R_texture.loadFromFile("right.png") ||
        !P2L_texture.loadFromFile("left.png") ||
        !P2R_texture.loadFromFile("right.png") ||
        !player1_texture.loadFromFile("tank1.png") ||
        !player2_texture.loadFromFile("tank1.png"))
    {
        cout << "Failed to load textures" << endl;
    }
    if (!background_TXT.loadFromFile("mainBackground.png")) {
        cout << "Failed to load background texture" << endl;
    }
    if (!logo_TXT.loadFromFile("gameLogo.png"))
    {
        cout << "Failed to load logo texture" << endl;
    }
    this->setTexture(background_TXT);

    P1L_sprite.setTexture(P1L_texture);
    P1L_sprite.setScale(0.1, 0.1);
    P1L_sprite.setPosition(400, 700);

    P1R_sprite.setTexture(P1R_texture);
    P1R_sprite.setScale(0.1, 0.1);
    P1R_sprite.setPosition(500, 700);

    P2L_sprite.setTexture(P2L_texture);
    P2L_sprite.setScale(0.1, 0.1);
    P2L_sprite.setPosition(1100, 700);

    P2R_sprite.setTexture(P2R_texture);
    P2R_sprite.setScale(0.1, 0.1);
    P2R_sprite.setPosition(1200, 700);

    player1_sprite.setTexture(player1_texture);
    player1_sprite.setScale(0.7, 0.7);
    player1_sprite.setPosition(300, 300);

    player2_sprite.setTexture(player2_texture);
    player2_sprite.setScale(0.7, 0.7);
    player2_sprite.setPosition(900, 300);

    playButton.setSize(Vector2f(200, 60));
    playButton.setFillColor(Color::White);
    playButton.setPosition(700, 800);

    closeButton.setOutlineColor(Color::Green);
    closeButton.setSize(Vector2f(200, 80));
    closeButton.setFillColor(Color::Black);
    closeButton.setPosition(50, 480);

    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Failed to load font" << endl;
    }

    player1Text.setFont(font);
    player1Text.setString("Player 1");
    player1Text.setCharacterSize(50);
    player1Text.setFillColor(Color::White);
    player1Text.setPosition(400, 100);
    player1Text.setOutlineColor(Color::Black);
    player1Text.setOutlineThickness(3);

    player2Text.setFont(font);
    player2Text.setString("Player 2");
    player2Text.setCharacterSize(50);
    player2Text.setFillColor(Color::White);
    player2Text.setPosition(1100, 100);
    player2Text.setOutlineColor(Color::Black);
    player2Text.setOutlineThickness(3);

    battleText.setFont(font);
    battleText.setString("BATTLE");
    battleText.setCharacterSize(50);
    battleText.setFillColor(Color::White);
    battleText.setPosition(710, 790);
    battleText.setOutlineColor(Color::Black);
    battleText.setOutlineThickness(3);
}

void Tankwindow::drawGraphics(RenderWindow& window)
{
	window.draw(*this);
	window.draw(player1_sprite);
	window.draw(player2_sprite);
	window.draw(P1L_sprite);
	window.draw(P1R_sprite);
	window.draw(P2L_sprite);
	window.draw(P2R_sprite);
    window.draw(playButton);
    window.draw(closeButton);
	window.draw(player1Text);
	window.draw(player2Text);
	window.draw(battleText);	
}



