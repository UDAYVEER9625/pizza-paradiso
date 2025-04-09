document.getElementById("signup-form").addEventListener("submit", registerUser);
document.getElementById("login-form").addEventListener("submit", loginUser);

function registerUser(event) {
    event.preventDefault();
    let userData = {
        name: document.getElementById("name").value,
        email: document.getElementById("email").value,
        phone: document.getElementById("phone").value,
        password: document.getElementById("password").value
    };

    fetch("/api/customers/register", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(userData)
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            alert("Registration successful! Please log in.");
            window.location.href = "customer.html";
        } else {
            alert("Error: " + data.message);
        }
    });
}

function loginUser(event) {
    event.preventDefault();
    let loginData = {
        email: document.getElementById("login-email").value,
        password: document.getElementById("login-password").value
    };

    fetch("/api/customers/login", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify(loginData)
    })
    .then(response => response.json())
    .then(data => {
        if (data.success) {
            localStorage.setItem("userToken", data.token);
            window.location.href = "index.html";
        } else {
            alert("Invalid credentials!");
        }
    });
}
