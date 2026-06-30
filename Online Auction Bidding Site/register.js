(function()
{
  const $ = id => document.getElementById(id);

  const emailRe = /^(?!\.)(?!.*\.\.)[A-Za-z0-9!#$%&'*+\-/=?^_`{|}~.]+(?<!\.)@(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?\.)+[A-Za-z]{2,}$/;

  $('btnReg').addEventListener('click', function(){
    const fname = $('fname').value.trim();
    const lname = $('lname').value.trim();
    const email = $('email').value.trim();
    const pass  = $('password').value;
    const rep   = $('repass').value;

    const msg = $('msg'); msg.className=''; msg.textContent='';

    if(!fname || !lname || !email || !pass || !rep){
      msg.textContent='Please fill all fields.'; msg.className='err'; return;
    }
    if(!emailRe.test(email)){
      msg.textContent='Invalid email format.'; msg.className='err'; return;
    }
    if(pass.length < 6){
      msg.textContent='Password must be at least 6 characters.'; msg.className='err'; return;
    }
    if(pass !== rep){
      msg.textContent='Passwords do not match.'; msg.className='err'; return;
    }

    const qs = new URLSearchParams({
      fname, lname, email, password: pass
    }).toString();

    const xhr = new XMLHttpRequest();
    xhr.open('GET', 'register.php?' + qs, true);
    xhr.onreadystatechange = function(){
      if(xhr.readyState === 4){
        if(xhr.status === 200){
          msg.innerHTML = xhr.responseText; // server prints success or specific error
        }else{
          msg.innerHTML = '<span class="err">Server error: '+xhr.status+'</span>';
        }
      }
    };
    xhr.send(null);
  });
})();
