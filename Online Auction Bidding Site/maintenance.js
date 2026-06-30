(function () {
  const $ = (s) => document.querySelector(s);
  const msg = $("#msg");
  const out = $("#out");

  function setMsg(text, ok = true) {
    msg.className = ok ? "ok" : "err";
    msg.textContent = text;
  }
  const money = (n) => "$" + Number(n || 0).toFixed(2);

  $("#btnProcess").addEventListener("click", async () => {
    setMsg("Processing…");
    out.innerHTML = "";
    try {
      const res = await fetch("maintenance_action.php", {
        method: "POST",
        headers: {"Content-Type": "application/x-www-form-urlencoded"},
        body: "action=process"
      });
      const j = await res.json();
      if (!j.ok) throw new Error(j.error || "Failed to process.");
      setMsg(`Done. Processed ${j.processed} items: SOLD=${j.sold}, FAILED=${j.failed}.`, true);
    } catch (e) {
      setMsg(e.message, false);
    }
  });

  $("#btnReport").addEventListener("click", async () => {
    setMsg("Generating report…");
    out.innerHTML = "";
    try {
      const remove = $("#removeAfter").checked ? "1" : "0";
      const res = await fetch("maintenance_action.php", {
        method: "POST",
        headers: {"Content-Type": "application/x-www-form-urlencoded"},
        body: "action=report&remove=" + remove
      });
      const j = await res.json();
      if (!j.ok) throw new Error(j.error || "Failed to generate report.");

      const rows = (arr) => arr.map(it => `
        <tr>
          <td>${it.id}</td>
          <td>${it.title}</td>
          <td>${it.category}</td>
          <td>${it.seller}</td>
          <td>${money(it.price)}</td>
          <td>${money(it.reserve)}</td>
          <td>${it.status}</td>
        </tr>`).join("");

      out.innerHTML = `
        <h3>Report</h3>
        <table>
          <thead>
            <tr>
              <th>ItemID</th><th>Title</th><th>Category</th>
              <th>Seller</th><th>Final Price</th><th>Reserve</th><th>Status</th>
            </tr>
          </thead>
          <tbody>
            ${rows(j.items)}
          </tbody>
          <tfoot>
            <tr><td colspan="7">Sold: ${j.summary.sold} &nbsp; | &nbsp; Failed: ${j.summary.failed}</td></tr>
            <tr><td colspan="7">Revenue: ${money(j.summary.revenue)}</td></tr>
          </tfoot>
        </table>
        <p class="small">${j.removed ? "Processed items have been removed from the XML." : ""}</p>
      `;
      setMsg("Report ready.", true);
    } catch (e) {
      setMsg(e.message, false);
    }
  });
})();
