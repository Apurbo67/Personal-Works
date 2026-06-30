(function () 
{
  "use strict";

  const list = document.getElementById("list");
  const msg  = document.getElementById("msg");

  const esc = (s) =>
    String(s ?? "").replace(/[&<>"']/g, (m) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;", "'": "&#39;" }[m]));
  const money = (n) => "$" + Number(n || 0).toFixed(2);

  function timeLeft(iso) {
    try {
      const end = new Date(iso);
      const now = new Date();
      let sec = Math.floor((end - now) / 1000);
      if (!isFinite(sec) || sec <= 0) return "Expired";
      const d = Math.floor(sec / 86400); sec %= 86400;
      const h = Math.floor(sec / 3600);  sec %= 3600;
      const m = Math.floor(sec / 60);    const s = sec % 60;
      const p = (v, w) => v + " " + w + (v === 1 ? "" : "s");
      return `${p(d, "day")} ${p(h, "hour")} ${p(m, "min")} ${p(s, "sec")} remaining`;
    } catch { return ""; }
  }

  const cut = (s, n) => {
    s = String(s || "");
    return s.length > n ? s.slice(0, n) + "..." : s;
  };

  function cardHTML(it) {
    const tl = timeLeft(it.endTime);
    const open = (it.status || "OPEN") === "OPEN" && tl !== "Expired";
    return `
      <div class="card">
        <div class="row"><b>Item No:</b> ${esc(it.id)}</div>
        <div class="row"><b>Item Name:</b> ${esc(it.title)}</div>
        <div class="row"><b>Category:</b> ${esc(it.category)}</div>
        <div class="row"><b>Description:</b> ${esc(cut(it.desc || "", 30))}</div>
        <div class="row"><b>Buy It Now Price:</b> ${money(it.buyNow)}</div>
        <div class="row"><b>Current Bid:</b> ${money(it.current)}</div>
        <div class="timeleft">${esc(tl)}</div>
        <div class="actions">
          ${open
            ? `<button type="button" class="bid" data-id="${esc(it.id)}">Place Bid</button>
               <button type="button" class="buy" data-id="${esc(it.id)}">Buy It Now</button>`
            : `<span>${it.status === "SOLD" ? "Item sold" : "Auction ended"}</span>`}
        </div>
      </div>`;
  }

  function render(items) {
    if (!Array.isArray(items) || items.length === 0) {
      list.innerHTML = '<p style="text-align:center;color:#666">No active auctions.</p>';
      return;
    }
    list.innerHTML = items.map(cardHTML).join("");
  }

  async function load() {
    try {
      msg.textContent = "";
      const res = await fetch("listing_feed.php?_=" + Date.now(), { cache: "no-store" });
      const data = await res.json();
      if (!data || data.ok === false) throw new Error((data && data.error) || "Failed to load listings.");

      const items = data.items.map((i) => ({
        id: i.id,
        title: i.title,
        category: i.category,
        desc: i.desc || "",
        buyNow: Number(i.buyNowPrice || 0),
        current: Number(i.current || 0),
        endTime: i.endTime,
        status: i.status || "OPEN",
      }));
      render(items);
    } catch (e) {
      msg.style.color = "#b00020";
      msg.textContent = "Error: " + e.message;
    }
  }

  // --- Handle buttons (POST, plain-text replies) ---
  document.addEventListener("click", async (ev) => {
    const b = ev.target.closest(".bid,.buy");
    if (!b) return;
    const id = b.dataset.id;

    try {
      if (b.classList.contains("bid")) {
        const val = prompt("Enter your bid amount:");
        if (val === null) return;
        const amt = parseFloat(val);
        if (isNaN(amt) || amt <= 0) { alert("Sorry, your bid is not valid."); return; }

        const body = new URLSearchParams({ itemID: id, amount: amt.toFixed(2) }).toString();
        const res  = await fetch("bidding_action.php", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body
        });
        const text = (await res.text()).trim();         // plain text per spec
        alert(text || "Done.");
        load();
        return;
      }

      if (b.classList.contains("buy")) {
        if (!confirm("Confirm Buy It Now?")) return;
        const body = new URLSearchParams({ itemID: id }).toString();
        const res  = await fetch("buy_action.php", {
          method: "POST",
          headers: { "Content-Type": "application/x-www-form-urlencoded" },
          body
        });
        const text = (await res.text()).trim();         // plain text per spec
        alert(text || "Done.");
        load();
        return;
      }
    } catch {
      alert("Network error. Please try again.");
    }
  });

  // initial load + 5s auto-refresh
  load();
  setInterval(load, 5000);
})();
