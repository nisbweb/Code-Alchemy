import pygame
import random
import numpy as np
import requests
from io import BytesIO

# Maze generation settings
WIDTH, HEIGHT = 600, 600  # Window size
CELL_SIZE = 30  # Size of each cell
GRID_WIDTH, GRID_HEIGHT = WIDTH // CELL_SIZE, HEIGHT // CELL_SIZE

# Pygame settings
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
TEXT_COLOR = (255, 0, 0) # Green color for the winning message

# Directions: (row_offset, col_offset)
DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# URLs for images
UFO_IMAGE_URL = "https://img.freepik.com/premium-psd/ufo-png_1296627-5535.jpg"  
EARTH_IMAGE_URL = "https://static.vecteezy.com/system/resources/previews/042/584/534/non_2x/ai-generated-earth-planet-isolated-on-transparent-background-free-png.png" 

# Function to load and scale images from URLs
def load_image_from_url(url, size):
    try:
        response = requests.get(url)
        response.raise_for_status()  # Check for errors
        image = pygame.image.load(BytesIO(response.content))
        return pygame.transform.scale(image, (size, size))
    except (requests.HTTPError, pygame.error) as e:
        print(f"Error loading image from {url}: {e}")
        return None

# Load images
ufo_image = load_image_from_url(UFO_IMAGE_URL, CELL_SIZE)
earth_image = load_image_from_url(EARTH_IMAGE_URL, CELL_SIZE)

# Function to draw the maze
def draw_maze(screen, maze):
    for row in range(GRID_HEIGHT):
        for col in range(GRID_WIDTH):
            if maze[row, col] == 1:  # Wall
                pygame.draw.rect(screen, BLACK, (col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE))

# Generate maze using Prim's algorithm
def generate_maze():
    maze = np.ones((GRID_HEIGHT, GRID_WIDTH), dtype=int)  # Initialize grid with walls (1s)
    start_row, start_col = random.randint(0, GRID_HEIGHT - 1), random.randint(0, GRID_WIDTH - 1)
    maze[start_row, start_col] = 0  # Start position

    walls = [(start_row, start_col)]
    while walls:
        row, col = random.choice(walls)
        walls.remove((row, col))

        if sum(maze[row + dr][col + dc] == 0 for dr, dc in DIRECTIONS if 0 <= row + dr < GRID_HEIGHT and 0 <= col + dc < GRID_WIDTH) <= 1:
            maze[row, col] = 0  # Make it a path

            # Add neighboring walls
            for dr, dc in DIRECTIONS:
                r, c = row + dr, col + dc
                if 0 <= r < GRID_HEIGHT and 0 <= c < GRID_WIDTH and maze[r, c] == 1:
                    walls.append((r, c))

    return maze

# Function to move the player
def move_player(player_pos, direction, maze):
    row, col = player_pos
    dr, dc = direction
    new_row, new_col = row + dr, col + dc
    if 0 <= new_row < GRID_HEIGHT and 0 <= new_col < GRID_WIDTH and maze[new_row, new_col] == 0:
        return new_row, new_col
    return player_pos

# Main game loop
def main():
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Maze Solver: Reach the Earth!")
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("Arial", 48, bold=True) # Font for displaying text

    # Generate maze and initialize player position
    maze = generate_maze()
    player_pos = (0, 0)  # Start at top-left corner
    target_pos = (GRID_HEIGHT - 1, GRID_WIDTH - 1)  # Goal at bottom-right corner
    won = False

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return

            # Move player with arrow keys
            if event.type == pygame.KEYDOWN and not won:
                if event.key == pygame.K_UP:
                    player_pos = move_player(player_pos, (-1, 0), maze)
                elif event.key == pygame.K_DOWN:
                    player_pos = move_player(player_pos, (1, 0), maze)
                elif event.key == pygame.K_LEFT:
                    player_pos = move_player(player_pos, (0, -1), maze)
                elif event.key == pygame.K_RIGHT:
                    player_pos = move_player(player_pos, (0, 1), maze)

        # Check if the player reached the target
        if player_pos == target_pos:
            won = True

        # Drawing the maze
        screen.fill(WHITE)
        draw_maze(screen, maze)

        # Draw player (UFO) and target (Earth)
        if ufo_image:
            screen.blit(ufo_image, (player_pos[1] * CELL_SIZE, player_pos[0] * CELL_SIZE))
        if earth_image:
            screen.blit(earth_image, (target_pos[1] * CELL_SIZE, target_pos[0] * CELL_SIZE))

        # Display winning message if player reaches the target
        if won:
            win_text = font.render("Mission Accomplished!", True, TEXT_COLOR)
            screen.blit(win_text, (WIDTH // 6, HEIGHT // 2))

        pygame.display.flip()
        clock.tick(30)  # FPS

if __name__ == "__main__":
    main()
