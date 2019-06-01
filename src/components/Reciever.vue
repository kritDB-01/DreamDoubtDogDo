

<template>
  <div :class="['textbox', {'isOff': offClass}]">
    {{message}}
  </div>
</template>

<script>
import { database } from 'firebase'
export default {
  name: 'Reciever',
  props: ['num'],
  data () {
    return {
      isOn: true,
      message: "xx",
      realtext: {
        "0": "",
        "1": "ไม่เข้าใจเลยนะอาจารย์",
        "2": "เบาไปแล้วค้าบบบ",
        "3": "ซิ่งไปคับจารร",
        "4": "Time Up NOW",
        "5": "เล็กไปค้าบบางที ตัวหนังสืออ่ะ",
        "6": "ลื่นจริงๆวันนี้",
        "7": "รีบหรอคร้าบบบ",
        "8": "เยอะจริงเลยนะค้าบเนี่ยย",
        "9": "จะหลับแล้วจาร"
      }
    }
  },
  mounted () {
    let data = database().ref("text")
    let self = this
    data.on('value', function(snapshot) {
      let msg = snapshot.val()
      msg = Object.values(msg)
      msg = msg.slice(-11)
      self.message = self.realtext[msg[self.num]]
      if(self.num == 10){
        self.isOn = false
      setTimeout(() => {
        self.isOn = true
      }, 2000);
      }
    })
  },
  computed: {
    offClass () {
      if (this.isOn) return false
      else return true
    }
  }
}
</script>

<style lang="scss" scoped>
  @import url('https://fonts.googleapis.com/css?family=Mitr&display=swap');
  .textbox{
    color: rgb(255, 255, 255);
    width: 300px;
    border-radius: 12px;
    margin: 5px;
    padding: 10px;
    border: 2px solid  black;
    background: rgb(221, 111, 111);
    font-family: 'Mitr', sans-serif;
  }
  .isOff{
    animation: show 3s; 
  }
  @keyframes show {
  0%   { background: red; }
  100% { background: rgb(230, 194, 194); }
}
</style>

