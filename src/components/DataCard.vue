<template>
  <div class="col-4">
    <h5>{{ name }}</h5>
    <h2>{{ value }}</h2>
  </div>
</template>

<script>
import { database } from 'firebase'
export default {
  name: 'DataCard',
  props: ['name', 'path'],
  data () {
    return {
      value: null
    }
  },
  mounted () {
    let data = database().ref(this.path)
    let self = this
    data.on('value', function(snapshot) {
        self.value = snapshot.val()
    })
  }
}
</script>
