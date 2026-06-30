// redirect to login if not signed in
(function(){
  var x=new XMLHttpRequest();
  x.open('GET','session_check.php',true);
  x.onreadystatechange=function(){
    if(x.readyState===4&&x.status===200){
      try{
        var r=JSON.parse(x.responseText);
        if(!r.ok){ location.href='login.htm'; }
      }catch(e){ location.href='login.htm'; }
    }
  };
  x.send(null);
})();

(function()
{
  const $ = id => document.getElementById(id);
  const money = v => /^(\d+)(\.\d{1,2})?$/.test(v);

  // Load categories from existing auction.xml + add "Other"
  function loadCategories(){
    const xhr = new XMLHttpRequest();
    xhr.open('GET', 'categories.php', true);
    xhr.onreadystatechange = function(){
      if(xhr.readyState === 4 && xhr.status === 200){
        const data = JSON.parse(xhr.responseText || '[]');
        const sel = $('cat');
        sel.innerHTML = '';
        // existing categories
        data.forEach(c => {
          const op = document.createElement('option');
          op.value = c; op.textContent = c;
          sel.appendChild(op);
        });
        // plus "Other"
        const other = document.createElement('option');
        other.value = '__OTHER__'; other.textContent = 'Other';
        sel.appendChild(other);

        toggleOther(); // set initial visibility
      }
    };
    xhr.send(null);
  }

  function toggleOther(){
    const show = $('cat').value === '__OTHER__';
    $('otherWrap').style.display = show ? 'block' : 'none';
  }

  $('cat').addEventListener('change', toggleOther);

  $('btnReset').addEventListener('click', function(){
    $('title').value = '';
    $('desc').value = '';
    $('start').value = '';
    $('reserve').value = '';
    $('buy').value = '';
    $('d').value = '0'; $('h').value = '7'; $('m').value = '0';
    $('msg').textContent = '';
    $('msg').className = '';
    loadCategories();
  });

  $('btnList').addEventListener('click', function(){
    const title = $('title').value.trim();
    const catSel = $('cat').value;
    const otherCat = $('otherCat').value.trim();
    const desc = $('desc').value.trim();
    const start = $('start').value.trim();
    const reserve = $('reserve').value.trim();
    const buy = $('buy').value.trim();
    const d = parseInt($('d').value,10) || 0;
    const h = parseInt($('h').value,10) || 0;
    const m = parseInt($('m').value,10) || 0;

    const msg = $('msg'); msg.className=''; msg.textContent='';

    // determine category
    let cat = catSel === '__OTHER__' ? otherCat : catSel;

    if(!title || !cat){ msg.textContent='Please fill Item Name and Category.'; msg.className='err'; return; }
    if(!money(start) || !money(reserve)){ msg.textContent='Start/Reserve must be valid amounts (e.g. 199.00).'; msg.className='err'; return; }
    if(parseFloat(reserve) < parseFloat(start)){ msg.textContent='Reserve price must be = Start price.'; msg.className='err'; return; }
    if(buy && !money(buy)){ msg.textContent='Buy-Now must be a valid amount.'; msg.className='err'; return; }
    if(buy && parseFloat(buy) < parseFloat(reserve)){ msg.textContent='Buy-Now must be = Reserve price.'; msg.className='err'; return; }

    // duration seconds (defaults to 7h in the UI like screenshot example)
    const dur_s = (d*24*3600) + (h*3600) + (m*60);
    if (dur_s <= 0){ msg.textContent='Duration must be greater than zero.'; msg.className='err'; return; }

    const qs = new URLSearchParams({
      title, cat, desc, start, reserve, buy, dur_s
    }).toString();

    const xhr = new XMLHttpRequest();
    xhr.open('GET', 'listing.php?' + qs, true);
    xhr.onreadystatechange = function(){
      if(xhr.readyState === 4){
        if(xhr.status === 200){
          msg.innerHTML = xhr.responseText;
        } else {
          msg.innerHTML = '<span class="err">Server error: '+xhr.status+'</span>';
        }
      }
    };
    xhr.send(null);
  });

  loadCategories();
})();
