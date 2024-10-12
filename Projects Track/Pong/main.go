//install Go nad run "go mod tidy" , this command installs all the neccsary modules in mentioned in the mod file 

package main

import (
	"image/color"
	"log"

	"github.com/hajimehoshi/ebiten/v2"
	"github.com/hajimehoshi/ebiten/v2/ebitenutil"
)

// Any chnages in physical attributes of the game can be changed here
const (
	screenWidth  = 640
	screenHeight = 480

	paddleWidth  = 10
	paddleHeight = 100
	paddleSpeed  = 8

	ballSize  = 13
	ballSpeed = 5
)

// Paddle Struct defines properties of the Paddle
type Paddle struct {
	x, y     float64
	width    float64
	height   float64
	speed    float64
	isPlayer bool
}

func (p *Paddle) Update() {
	if p.isPlayer {
		//if key is pressed W or S on one side
		if ebiten.IsKeyPressed(ebiten.KeyW) && p.y > 0 {
			p.y -= p.speed //Plus the paddle is only able to move in one direction
		}
		if ebiten.IsKeyPressed(ebiten.KeyS) && p.y < screenHeight-p.height {
			p.y += p.speed
		}
	} else { //Here the up and down key is pressed
		if ebiten.IsKeyPressed(ebiten.KeyUp) && p.y > 0 {
			p.y -= p.speed
		}
		if ebiten.IsKeyPressed(ebiten.KeyDown) && p.y < screenHeight-p.height {
			p.y += p.speed
		}
	}
}

// This method is used to Draw the paddle
func (p *Paddle) Draw(screen *ebiten.Image) {
	ebitenutil.DrawRect(screen, p.x, p.y, p.width, p.height, color.White)
}

// Physical atrributes of the Ball
type Ball struct {
	x, y   float64
	width  float64
	height float64
	xSpeed float64
	ySpeed float64
}

func (b *Ball) Update(p1, p2 *Paddle) {
	b.x += b.xSpeed
	b.y += b.ySpeed
	//Bounces of the screen border
	if b.y < 0 || b.y+b.height > screenHeight {
		b.ySpeed = -b.ySpeed
	}

	//collision with player 1
	if b.x < p1.x+p1.width && b.x > p1.x && b.y > p1.y && b.y < p1.y+p1.height {
		b.xSpeed = -b.xSpeed
	}

	//collision with player 2
	if b.x+b.width > p2.x && b.x+b.width < p2.x+p2.width && b.y > p2.y && b.y < p2.y+p2.height {
		b.xSpeed = -b.xSpeed
	}

	//Resets the ball
	if b.x < 0 || b.x > screenWidth {
		b.x = screenWidth / 2
		b.y = screenHeight / 2
		b.xSpeed = -b.xSpeed
		b.ySpeed = ballSpeed
	}
}

func (b *Ball) Draw(screen *ebiten.Image) {
	ebitenutil.DrawRect(screen, b.x, b.y, b.width, b.height, color.RGBA{255, 0, 0, 255})
}

// The elemets of the game
type Game struct {
	player1 *Paddle
	player2 *Paddle
	ball    *Ball
}

// Its in loop to position paddles and balls
func (g *Game) Update() error {
	g.player1.Update()
	g.player2.Update()
	g.ball.Update(g.player1, g.player2)
	return nil
}

func (g *Game) Draw(screen *ebiten.Image) {
	g.player1.Draw(screen)
	g.player2.Draw(screen)
	g.ball.Draw(screen)
}

func (g *Game) Layout(outsideWidth, outsideHeight int) (int, int) {
	return screenWidth, screenHeight
}

func main() {
	game := &Game{
		player1: &Paddle{x: 10, y: float64(screenHeight/2 - paddleHeight/2), width: paddleWidth, height: paddleHeight, speed: paddleSpeed, isPlayer: true},
		player2: &Paddle{x: float64(screenWidth - paddleWidth - 10), y: float64(screenHeight/2 - paddleHeight/2), width: paddleWidth, height: paddleHeight, speed: paddleSpeed, isPlayer: false},
		ball:    &Ball{x: float64(screenWidth / 2), y: float64(screenHeight / 2), width: ballSize, height: ballSize, xSpeed: ballSpeed, ySpeed: ballSpeed},
	}

	ebiten.SetWindowSize(screenWidth, screenHeight)
	ebiten.SetWindowTitle("Pong Game")

	if err := ebiten.RunGame(game); err != nil {
		log.Fatal(err)
	}
}
