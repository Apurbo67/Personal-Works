(function()
{
  const $ = id => document.getElementById(id);
  $('btnLogin').addEventListener('click', function(){
    const email = $('email').value.trim();
    const pass  = $('password').value;
    const msg = $('msg'); msg.className=''; msg.textContent='';
    if(!email || !pass){ msg.textContent='Please enter email and password.'; msg.className='err'; return; }
    const xhr = new XMLHttpRequest();
    xhr.open('POST','login.php',true);
    xhr.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
    xhr.onreadystatechange=function()
{
      if(xhr.readyState===4){
        if(xhr.status===200){
          try{
            var r = JSON.parse(xhr.responseText);
            if(r.ok){
              msg.className='ok'; msg.textContent='Welcome, '+r.name+'. Redirecting...';
              setTimeout(function(){ location.href='home.htm'; },700);
            }else{
              msg.className='err'; msg.textContent=r.error||'Login failed';
            }
          }catch(e){ msg.className='err'; msg.textContent='Server error'; }
        }else{ msg.className='err'; msg.textContent='Server error '+xhr.status; }
      }
    };
    xhr.send('email='+encodeURIComponent(email)+'&password='+encodeURIComponent(pass));
  });
})();
