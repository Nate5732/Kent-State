// Login Validation
function validateLogin() {
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    const validUsername = 'username';
    const validPassword = 'password';

    if (username === validUsername && password === validPassword) {
        alert('Login successful!');
        window.location.href = 'RYUG.html';
    } else {
        alert('Invalid username or password. Please try again.');
    }
}

// Discount Tile Game
// https://stackoverflow.com/questions/44361917/building-memory-game-minigame-in-jquery-javascript
// Referenced this stackoverflow forumn to help create discount tile game with js and css.
document.addEventListener("DOMContentLoaded", () => {
    if (window.location.pathname.endsWith('discount.html')) {
        const tilesContainer = document.querySelector(".tiles");
        const resetButton = document.getElementById("resetButton");
        const discounts = ["10% OFF", "15% OFF", "20% OFF", "25% OFF", "30% OFF", "35% OFF", "40% OFF", "50% OFF", "Free!"];
        let clicked = false;

        const createTile = (discount) => { // Creating a tile here
            const tile = document.createElement("div");
            tile.classList.add("tile");
            tile.innerHTML = `
                <div class="tile-inner"> 
                    <div class="tile-front">?</div>
                    <div class="tile-back">${discount}</div>
                </div>`;
            tile.addEventListener("click", () => {
                if (!clicked) {
                    tile.classList.add("flipped");
                    clicked = true;
                }
            });
            return tile;
        };

        // Rendering tiles
        const renderTiles = () => {
            tilesContainer.innerHTML = "";
            clicked = false;
            discounts.sort(() => Math.random() - 0.5).forEach((discount) => {
                tilesContainer.appendChild(createTile(discount));
            });
        };

        renderTiles();

        // Play again button to reset the game
        resetButton.addEventListener("click", renderTiles);
    }
});

// Word Counter
// https://stackoverflow.com/questions/38382252/how-to-use-javascript-to-count-words-on-a-page
// Referenced this page to create word counting function to display on every page.
function countWords() {
    const text = document.body.innerText;
    const words = text.trim().split(/\s+/);
    const wordCount = words.length;

    document.getElementById('wordCountBox').textContent = `Word count: ${wordCount}`;
}

// Ka-Ching button implementation to play audio file located on items.html page
if (window.location.pathname.endsWith('items.html')) {
    const kaChingButton = document.getElementById('kaChingButton');
    const kaChingSound = document.getElementById('kaChingSound');

    if (kaChingButton && kaChingSound) {
        kaChingButton.addEventListener('click', () => {
            kaChingSound.play();
        });
    }
}


// Scrolling Text
document.addEventListener("DOMContentLoaded", () => {
    if (window.location.pathname.endsWith('history.html')) {
        
        const scrollingTextContainer = document.getElementById("scrollingTextContainer");
        const scrollingText = document.getElementById("scrollingText");
        
        let isScrolling = false;
        
        scrollingText.style.animationPlayState = 'paused';
        
        scrollingTextContainer.addEventListener('click', () => {
            if (isScrolling) {
                scrollingText.style.animationPlayState = 'paused';
            } else {
                scrollingText.style.animationPlayState = 'running';
            }
            
            isScrolling = !isScrolling;
        });
    }
});

// Table Search
function filterTable() {
    const searchInput = document.getElementById('searchInput').value.toLowerCase();
    const table = document.getElementById('itemTable');
    const rows = table.querySelectorAll('tbody tr');

    rows.forEach(row => {
        const itemName = row.querySelector('td:nth-child(2)').textContent.toLowerCase();
        if (itemName.includes(searchInput)) {
            row.style.display = '';
        } else {
            row.style.display = 'none';
        }
    });
    countWords(); // Used countWords function to update value based upon new results shown after search

}


