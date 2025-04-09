document.addEventListener("DOMContentLoaded", loadCart);

function loadCart() {
    let cart = JSON.parse(localStorage.getItem("cart")) || [];
    const cartContainer = document.getElementById("cart-items");
    cartContainer.innerHTML = "";
    let total = 0;

    cart.forEach(item => {
        fetch(`/api/pizzas/${item}`)
            .then(response => response.json())
            .then(pizza => {
                cartContainer.innerHTML += `
                    <div class="cart-item">
                        <img src="${pizza.image}" alt="${pizza.name}">
                        <h3>${pizza.name}</h3>
                        <p>₹${pizza.price}</p>
                        <button onclick="removeFromCart(${pizza.pizzaID})">Remove</button>
                    </div>`;
                total += pizza.price;
                document.getElementById("cart-total").innerText = `Total: ₹${total}`;
            });
    });
}

function removeFromCart(pizzaID) {
    let cart = JSON.parse(localStorage.getItem("cart")) || [];
    cart = cart.filter(id => id !== pizzaID);
    localStorage.setItem("cart", JSON.stringify(cart));
    loadCart();
}
