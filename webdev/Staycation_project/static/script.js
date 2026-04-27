// SHOW / HIDE FUNCTION
function toggleContent() {
    const content = document.getElementById("hiddenContent");
    const button = document.querySelector("button");

    if (content.style.display === "none") {
        content.style.display = "block";
        button.textContent = "Hide Hidden Facts";
    } else {
        content.style.display = "none";
        button.textContent = "Show Hidden Facts";
    }
}


// HOVER IMAGE SWAP
const hoverImage = document.getElementById("hoverImage");

if (hoverImage) {
    const originalSrc = hoverImage.src;

    hoverImage.addEventListener("mouseover", function () {
        hoverImage.src = hoverImage.src.replace("timp_day", "timp_sunset");
    });

    hoverImage.addEventListener("mouseout", function () {
        hoverImage.src = originalSrc;
    });
}